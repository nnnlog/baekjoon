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

ll dp[100001][2];
const ll MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vl a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) cin >> b[i];

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] * (a[i] + b[i - 1]) + dp[i - 1][1] * (a[i] + b[i - 1] - 1);
		dp[i][1] = dp[i - 1][0] * b[i] + dp[i - 1][1] * (b[i]);

		dp[i][0] %= MOD;
		dp[i][1] %= MOD;
	}

	cout << dp[n][0];
}
