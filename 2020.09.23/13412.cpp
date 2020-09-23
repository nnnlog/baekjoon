#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int a, cnt = 0; cin >> a;
		for (int i = 1; i <= sqrt(a); i++) {
			if (a % i == 0) {
				int b = a / i;
				if ((i == 1 || i != b) && __gcd(i, b) == 1) cnt++;
			}
		}

		cout << cnt << "\n";
	}
}
