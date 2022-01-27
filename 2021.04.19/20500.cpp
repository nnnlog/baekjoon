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

int dp[1516][3][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	dp[1][1][0] = dp[1][2][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= 2; j++) {
			dp[i][j][0] = (dp[i - 1][(j + 2) % 3][0] + dp[i - 1][(j + 2) % 3][1]) % ((int)1e9 + 7);
			dp[i][j][1] = (dp[i - 1][(j + 1) % 3][0] + dp[i - 1][(j + 1) % 3][1]) % ((int)1e9 + 7);
		}

	cout << dp[n][0][1];
}
