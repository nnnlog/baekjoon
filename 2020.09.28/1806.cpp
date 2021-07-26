#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n, s, ans = 1e9;
	cin >> n >> s;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	int l = 0, r = 0, sum = arr[0];
	while (l <= n && r <= n) {
		if (sum >= s) ans = min(ans, r - l + 1);

		//cout << l << " " << r << " " << sum << "\n";

		if (sum < s) {
			r++;
			if (r >= n) break;
			sum += arr[r];
		} else {
			if (++l >= r) {
				if (l >= n) break;
				r = l;
				sum = arr[r];
			} else {
				sum -= arr[l - 1];
			}
		}
	}

	cout << (ans == 1e9 ? 0 : ans);
}
