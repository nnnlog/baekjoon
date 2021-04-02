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

int dp[1001][4], mp[1001][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++) cin >> mp[i][j];

	int ans = 1e9;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) dp[1][j] = 1e9;
		dp[1][i] = mp[1][i];
		for (int j = 2; j <= n; j++) {
			dp[j][1] = min(dp[j - 1][2], dp[j - 1][3]) + mp[j][1];
			dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + mp[j][2];
			dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + mp[j][3];
		}

		for (int j = 1; j <= 3; j++) if (i != j) ans = min(ans, min(dp[n][j], dp[n][j]));
	}

	cout << ans;
}
