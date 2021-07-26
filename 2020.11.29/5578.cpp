#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int mp[91][91], ans, n, m;
vector<pii> mv = {
		{-1, 0},
		{0,  -1},
		{1,  0},
		{0,  1},
};

int dfs(int x, int y) {
	//cout << x << " " << y << "\n";
	int c = 0;
	for (const auto &i : mv) {
		int xx = i.first + x, yy = y + i.second;
		if (xx < 1 || yy < 1 || xx > n || yy > m || !mp[xx][yy]) continue;
		mp[xx][yy] = 0;
		c = max(c, dfs(xx, yy) + 1);
		mp[xx][yy] = 1;
	}
	return c;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mp[i][j]) mp[i][j] = 0, ans = max(ans, dfs(i, j) + 1), mp[i][j] = 1;

	cout << ans;
}
