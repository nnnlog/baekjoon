#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

//1: 상(x-1), 2: 우(y+1), 3: 하(x+1), 4: 좌(y-1)
int vis[2000][2000][4], mp[2000][2000], n, m;

void solve(int i, int j, int direction) {
	if (i < 0 || i >= n || j < 0 || j >= m) return;
	if (vis[i][j][direction - 1]) return;
	vis[i][j][direction - 1] = 1;
	if (!mp[i][j] || mp[i][j] == 9) {
		switch (direction) {
			case 1:
				--i;
				break;
			case 2:
				++j;
				break;
			case 3:
				++i;
				break;
			case 4:
				--j;
				break;
		}
		solve(i, j, direction);
	} else {
		switch (mp[i][j]) {
			case 1:
				if (direction == 1 || direction == 3) break;
				if (direction == 2) direction = 4;
				else direction = 2;
				break;
			case 2:
				if (direction == 2 || direction == 4) break;
				if (direction == 1) direction = 3;
				else direction = 1;
				break;
			case 4:
				if (direction == 1) direction = 4;
				else if (direction == 2) direction = 3;
				else if (direction == 3) direction = 2;
				else direction = 1;
				break;
			case 3:
				if (direction == 1) direction = 2;
				else if (direction == 2) direction = 1;
				else if (direction == 3) direction = 4;
				else direction = 3;
				break;
		}
		switch (direction) {
			case 1:
				--i;
				break;
			case 2:
				++j;
				break;
			case 3:
				++i;
				break;
			case 4:
				--j;
				break;
		}
		solve(i, j, direction);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (mp[i][j] == 9) for (int d = 1; d <= 4; d++) solve(i, j, d);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			ans += (vis[i][j][0] || vis[i][j][1] || vis[i][j][2] || vis[i][j][3]);
	}
	cout << ans;
}
