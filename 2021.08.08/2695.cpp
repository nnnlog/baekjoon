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

int dp[51][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (i == 1) dp[i][j] = j - 1;
			else if (j > 1) {
				dp[i][j] = 1e9;
				for (int k = 1; k <= j; k++) {
					dp[i][j] = min(dp[i][j], max(dp[i - 1][k], dp[i][j - k]) + 1);
				}
			}
		}
	}

	int T; cin >> T;
	while (T--) {
		int a, b; cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
}
