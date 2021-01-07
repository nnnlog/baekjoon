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

int dp[2001][2001], n, vec[2001];

int solve(int l, int r) {
	int &ret = dp[l][r];
	if (ret) return ret;
	if (l > r) return 0;
	int c = l + n - r;
	return ret =
			       max(
					       solve(l + 1, r) + c * vec[l],
					       solve(l, r - 1) + c * vec[r]
			       );
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> vec[i];
	cout << solve(1, n);
}
