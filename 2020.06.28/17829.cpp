#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	short n;
	cin >> n;

	vector<vector<short>> before(n + 1, vector<short>(n + 1));
	for (short i = 1; i <= n; i++)
		for (short j = 1; j <= n; j++) cin >> before[i][j];

	while (n > 1) {
		for (short i = 1; i <= n; i += 2)
			for (short j = 1; j <= n; j += 2) {
				vector<short> l = {
						before[i][j],
						before[i][j + 1],
						before[i + 1][j],
						before[i + 1][j + 1]
				};
				sort(l.begin(), l.end());

				before[i / 2 + 1][j / 2 + 1] = l[2];
			}

		n /= 2;
	}

	cout << before[1][1];
}