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

	int n, m;
	cin >> n >> m;
	vector<vi> vec(n + 1, vi(m + 1)), dp(n + 1, vi(m + 1, -1e9));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> vec[i][j];

	dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		vi R(m + 1, -1e9), L(m + 1, -1e9);
		for (int j = 1; j <= m; j++) {
			R[j] = max(dp[i - 1][j], R[j - 1]) + vec[i][j];
		}
		for (int j = m; j >= 1; j--) {
			L[j] = max(dp[i - 1][j], j < m ? L[j + 1] : (int)-1e9) + vec[i][j];
		}
		for (int j = 1; j <= m; j++) dp[i][j] = max(L[j], R[j]);
	}

	cout << dp.back().back();
}
