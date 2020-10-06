#include <bits/stdc++.h>

using namespace std;

int graph[251][251];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (a) graph[i][j] = 1;
		}

	long long ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			long long cnt = 0;
			for (int k = 1; k <= n; k++) {
				if (i == j || j == k || i == k) continue;
				if (graph[i][k] && graph[j][k]) cnt++;
			}
			//cout << i << " " << j << " " << cnt << "\n";
			ans += cnt * (cnt - 1);
		}

	cout << ans;
}
