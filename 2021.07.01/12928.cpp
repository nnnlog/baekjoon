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

int dp[51][101][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, s; cin >> n >> s;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 2 * (n - 1); j++) {
			for (int k = 0; k <= s; k++) {
				if (!dp[i - 1][j][k]) continue;
				for (int add = 1;; add++) {
					if (j + add > 2 * (n - 1)) break;
					if (k + add * (add - 1) / 2 > s) break;
					dp[i][j + add][k + add * (add - 1) / 2] = 1;
					//cout << i << " " << j + add << " " << k + add * (add - 1) / 2 << "\n";
				}
			}
		}
	}

	cout << dp[n][2 * (n - 1)][s];
}
