#include <bits/stdc++.h>

using namespace std;

vector<int> x, y, z;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int b, c, d, sum = 0;
	cin >> b >> c >> d;

	while (b--) {
		int a;
		cin >> a;
		x.push_back(a);
		sum += a;
	}
	while (c--) {
		int a;
		cin >> a;
		y.push_back(a);
		sum += a;
	}
	while (d--) {
		int a;
		cin >> a;
		z.push_back(a);
		sum += a;
	}

	sort(x.begin(), x.end(), greater<>());
	sort(y.begin(), y.end(), greater<>());
	sort(z.begin(), z.end(), greater<>());
	int min_value = min(min(x.size(), y.size()), z.size());
	int ans = 0;
	for (int i = 1; i <= x.size(); i++) {
		ans += x[i - 1] * (i <= min_value ? 0.9 : 1);
	}
	for (int i = 1; i <= y.size(); i++) {
		ans += y[i - 1] * (i <= min_value ? 0.9 : 1);
	}
	for (int i = 1; i <= z.size(); i++) {
		ans += z[i - 1] * (i <= min_value ? 0.9 : 1);
	}
	cout << sum << "\n" << ans;
}
