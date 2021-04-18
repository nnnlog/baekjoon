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

int n, m;
int mp[51][51], dp[51][51][51][51], sum[51][51];

int get(int a, int b, int x, int y) {
	return sum[x][y] - sum[a - 1][y] - sum[x][b - 1] + sum[a - 1][b - 1];
}

int solve(int a, int b, int c, int d) {
	if (a == c && b == d) return 0;
	int &ret = dp[a][b][c][d];
	if (ret) return ret;
	ret = 1e9;
	for (int i = a; i < c; i++) ret = min(ret, solve(a, b, i, d) + solve(i + 1, b, c, d));
	for (int i = b; i < d; i++) ret = min(ret, solve(a, b, c, i) + solve(a, i + 1, c, d));
	return ret += get(a, b, c, d);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> mp[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mp[i][j];

	cout << solve(1, 1, n, m);
}
