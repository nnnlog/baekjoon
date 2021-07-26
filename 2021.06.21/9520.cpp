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

int dist[1501][1501], dp[1501][1501], n;

int solve(int l, int r) {
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	int curr = max(l, r) + 1;
	if (curr > n) return 0;
	ret = 1e9;
	ret = min(ret, solve(curr, r) + dist[curr][l]);
	ret = min(ret, solve(l, curr) + dist[r][curr]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof (dp));

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> dist[i][j];

	cout << solve(1, 1);
}
