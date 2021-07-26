#include <bits/stdc++.h>

using namespace std;

bool arr[50][50];
int cnt[50];

int main() {
	int n, m;
	cin >> n >> m;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			char a;
			cin >> a;
			arr[x][y] = a == '1';
			cnt[y] += arr[x][y];
		}
	int k;
	cin >> k;

	int ans = 0;
	for (int y = 0; y < n; y++) {
		vector<pair<int, int>> vis;
		bool flag = false;
		for (int x = 0; x < m; x++) {
			if (!arr[x][y]) {
				if ((vis.size() / n) > k) {
					flag = true;
					break;
				}

				for (int yy = 0; yy < n; yy++) {
					vis.emplace_back(x, yy);
					arr[x][yy] = !arr[x][yy];
					if (arr[x][yy]) cnt[yy]++;
					else cnt[yy]--;
				}
			}
		}

		if (!flag && (vis.size() / n) <= k && ((vis.size() / n) - k) % 2 == 0) {
			int sum = 0;
			for (int yy = 0; yy < n; yy++) if (cnt[yy] == m) sum++;
			ans = max(sum, ans);
		}

		for (const auto &v : vis) {
			arr[v.first][v.second] = !arr[v.first][v.second];
			if (arr[v.first][v.second]) cnt[v.second]++;
			else cnt[v.second]--;
		}
	}

	cout << ans;
}
