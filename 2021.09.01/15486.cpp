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

	int n; cin >> n;
	vpii vec(n);
	vi dp(n + 1);
	for (int i = 0; i < n; i++) {
		if (i) dp[i] = max(dp[i], dp[i - 1]);
		int a, b; cin >> a >> b;
		if (i + a <= n) dp[i + a] = max(dp[i + a], dp[i] + b);
	}
	cout << max(dp[n - 1], dp[n]);
}
