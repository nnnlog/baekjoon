#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int n, k, sum, mp[201][3], dp[201][3][201];

int solve(int x, int y, int c) {
	if (c < 1) return 0;
	int &ret = dp[x][y][c];
	if (ret != 1e9) return ret;
	ret = 1e8;
	for (int a = x + 1; a <= n; a++) {
		ret = min(ret, solve(a, y, c - 1) + mp[a][y]);
		if (a != x + 1) ret = min(ret, solve(a, y % 2 + 1, c - 1) + mp[a][y % 2 + 1]); //1->2, 2->1
	}
	return ret;
}

void init() {
	for (auto &i : dp)
		for (auto &j : i)
			for (auto &_k : j) _k = 1e9;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> mp[i][1] >> mp[i][2], sum += mp[i][1] + mp[i][2];

	init();
	int ans = solve(0, 1, k);

	init();
	ans = min(ans, solve(0, 2, k));

	cout << sum - ans;
}
