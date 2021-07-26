#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int n, k;
vpii cor;
int dp[501][501];

int solve(int i, int c) {
	if (c > k) return 1e9;
	if (i == n - 1 && c == k) return 0;
	else if (i >= n - 1) return 1e9;
	int &ret = dp[i][c];
	if (ret) return ret;
	ret = 1e9;
	for (int j = i + 1; j < n; j++) {
		int jump = j - i - 1;
		ret = min(solve(j, jump + c) + abs(cor[i].first - cor[j].first) + abs(cor[i].second - cor[j].second), ret);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	cor.resize(n);
	for (auto &[a, b] : cor) cin >> a >> b;

	cout << solve(0, 0);
}
