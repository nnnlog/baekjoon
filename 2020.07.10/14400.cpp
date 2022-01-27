#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> x, y;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	long long ans = 0;
	for (const int &a : x) ans += abs(a - x[n / 2]);
	for (const int &a : y) ans += abs(a - y[n / 2]);

	cout << ans;
}