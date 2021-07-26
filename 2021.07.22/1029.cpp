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

int dp[15][(1 << 16) - 1][10];
int w[15][15], n;

int solve(int u, int flag, int k) {
	int &ret = dp[u][flag][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int v = 0; v < n; v++) {
		if (flag & (1 << v)) continue;
		if (w[u][v] < k) continue;
		ret = max(ret, solve(v, flag | (1 << v), w[u][v]));
	}
	++ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof dp);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			w[i][j] = c - '0';
		}
	cout << solve(0, 1, 0);
}
