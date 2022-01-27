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

int dp[401][401][401];
vi A(1), B(1);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a) A.emplace_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a) B.emplace_back(a);
	}

	for (auto &i : dp) for (auto &j : i) for (auto &k : j) k = -1e9;

	for (int k = 0; k <= n; k++) dp[k][k][0] = 0;

	int ans = -1e9;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < A.size(); i++)
			for (int j = 1; j < B.size(); j++)
				dp[k][i][j] = max(dp[k - 1][i - 1][j], max(dp[k - 1][i][j - 1], dp[k - 1][i - 1][j - 1] + A[i] * B[j]));
		ans = max(ans, dp[k][A.size() - 1][B.size() - 1]);
	}

	cout << ans;
}
