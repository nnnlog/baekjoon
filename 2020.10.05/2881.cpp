#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> xAxis, yAxis;
unordered_map<int, unordered_map<int, int>> mp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int p; cin >> p;
	while (p--) {
		int x, y; cin >> x >> y;
		xAxis[x].push_back(y);
		yAxis[y].push_back(x);

		mp[x][y] = 1;
	}

	for (auto &v : xAxis) sort(v.second.begin(), v.second.end());
	for (auto &v : yAxis) sort(v.second.begin(), v.second.end());

	int q; cin >> q;
	while (q--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		//(x1, y1) ~ (x1, y2), y축
		//(x1, y1) ~ (x2, y1), x축
		//(x2, y1) ~ (x2, y2), y축
		//(x2, y2) ~ (x1, y2), x축

		int ans = 0;
		ans += upper_bound(xAxis[x1].begin(), xAxis[x1].end(), y2) - lower_bound(xAxis[x1].begin(), xAxis[x1].end(), y1);
		ans += upper_bound(xAxis[x2].begin(), xAxis[x2].end(), y2) - lower_bound(xAxis[x2].begin(), xAxis[x2].end(), y1);

		ans += upper_bound(yAxis[y1].begin(), yAxis[y1].end(), x2) - lower_bound(yAxis[y1].begin(), yAxis[y1].end(), x1);
		ans += upper_bound(yAxis[y2].begin(), yAxis[y2].end(), x2) - lower_bound(yAxis[y2].begin(), yAxis[y2].end(), x1);

		if (mp[x1][y1]) ans--;
		if (mp[x1][y2]) ans--;
		if (mp[x2][y1]) ans--;
		if (mp[x2][y2]) ans--;

		cout << ans << "\n";
	}
}
