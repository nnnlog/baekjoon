#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= n; x++) {
				if (x == 1 || x == n || y == 1 || y == n) cout << "#";
				else cout << "J";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}
