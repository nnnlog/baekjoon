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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, ans = 0;
	cin >> n;
	vector<vi> dp(n + 1, vi(n + 1, -1e9));
	for (int i = 1; i <= n; i++) cin >> dp[i][i], ans = max(ans, dp[i][i]);
	for (int i = n; i; i--)
		for (int j = i; j <= n; j++) {
			for (int k = i; k < j; k++)
				dp[i][j] = max(dp[i][j], dp[i][k] != -1e9 && dp[i][k] == dp[k + 1][j] ? dp[i][k] + 1 : (int)-1e9);
			ans = max(ans, dp[i][j]);
		}

	cout << ans;
}
