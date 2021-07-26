#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n) {
		int ans = 0;
		for (int i = 1; i * i <= n; i++) {
			if (i * i == n) {
				ans++;
				break;
			}
			for (int j = i; j * j <= n - i * i; j++) {
				if (j * j == n - i * i) {
					ans++;
					break;
				}
				for (int k = j; k * k <= n - i * i - j * j; k++) {
					if (k * k == n - i * i - j * j) {
						ans++;
						break;
					}
					for (int l = k; l * l <= n - i * i - j * j - k * k; l++) {
						if (l * l == n - i * i - j * j - k * k) {
							ans++;
							break;
						}
					}
				}
			}
		}
		cout << ans << "\n";
		cin >> n;
	}
}
