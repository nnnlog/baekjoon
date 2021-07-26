#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n, c; cin >> n >> c;
	vector<int> color[10001], vec(n + 1);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (color[a].empty()) color[a].push_back(-1);
		color[a].push_back(i);

		vec[i] = a;
	}


	random_device rd;
	mt19937 mt(rd());

	int m; cin >> m;
	while (m--) {
		int ans = -1;
		int a, b; cin >> a >> b;
		--a, --b;

		uniform_int_distribution<int> dist(a, b);
		for (int i = 0; i < 50; i++) {
			int _color = vec[dist(mt)];
			int cnt = upper_bound(color[_color].begin(), color[_color].end(), b) - lower_bound(color[_color].begin(), color[_color].end(), a);
			//cout << a << " " << b << " " << _color << " : " << cnt << "\n";
			if (cnt * 2 > b - a + 1) {
				ans = _color;
				break;
			}
		}

		if (ans == -1) cout << "no\n";
		else cout << "yes " << ans << "\n";
	}
}
