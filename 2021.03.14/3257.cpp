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

	string a, b, t; cin >> a >> b >> t;
	vector<vector<string>> dp(a.size() + 2, vector<string>(b.size() + 2));

	string ans;
	dp[0][0] = "0";
	for (int i = 0; i <= a.size(); i++) {
		for (int j = 0; j <= b.size(); j++) {
			if (!dp[i][j].empty()) {
				if (t[i + j] == a[i] && i < a.size()) dp[i + 1][j] = dp[i][j] + "1";
				if (t[i + j] == b[j] && j < b.size()) dp[i][j + 1] = dp[i][j] + "2";
				if (dp[i + 1][j].size() > ans.size()) ans = dp[i + 1][j];
				if (dp[i][j + 1].size() > ans.size()) ans = dp[i][j + 1];
				//cout << i << " " << j << " " << dp[i + 1][j] << "\n";
				//cout << i << " " << j << " " << dp[i][j + 1] << "\n";
			}
		}
	}

	cout << ans.substr(1);
}
