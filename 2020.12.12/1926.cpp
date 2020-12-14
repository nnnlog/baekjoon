#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int arr[501][501];
vector<pii> mv = {
		{1,  0},
		{0,  1},
		{-1, 0},
		{0,  -1}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0, all = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			if (arr[i][j]) {
				arr[i][j] = 0;
				cnt = 1;
				++all;

				queue<pii> q;
				q.emplace(i, j);
				while (!q.empty()) {
					auto f = q.front(); q.pop();
					for (auto &v : mv) {
						int x = f.first + v.first, y = f.second + v.second;
						if (x < 0 || y < 0 || x >= n || y >= m) continue;
						if (arr[x][y]) {
							arr[x][y] = 0;
							q.emplace(x, y);
							cnt++;
						}
					}
				}
			}
			ans = max(ans, cnt);
		}
	}

	cout << all << endl << ans;
}
