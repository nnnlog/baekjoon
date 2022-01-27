#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	vector<int> shooter;
	int m, n, l;
	cin >> m >> n >> l;
	while (m--) {
		int a;
		cin >> a;
		shooter.push_back(a);
	}

	sort(shooter.begin(), shooter.end());

	int ans = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;

		auto ptr = min(shooter.end() - 1, lower_bound(shooter.begin(), shooter.end(), x));
		int right = *ptr, left = *(max(shooter.begin(), ptr - 1));

		int sel = right;
		if (right - x > x - left) sel = left;

		if (abs(sel - x) + y <= l) ans++;
	}

	cout << ans;
}