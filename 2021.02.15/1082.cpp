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

string max(const string& a, const string& b) {
	return (a.size() != b.size()) ? (a.size() > b.size() ? a : b) : (a.compare(b) > 0 ? a : b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vi vec(n);
	for (auto &i : vec) cin >> i;

	int p; cin >> p;
	vector<string> dp(p + 1);
	dp[0] = "A";
	string ans = "A0";
	for (int i = n - 1; i >= 0; i--) {
		for (int k = vec[i]; k <= p; k++) {
			if (!dp[k - vec[i]].empty() && (i || k - vec[i])) dp[k] = max(dp[k], dp[k - vec[i]] + string(1, i + '0')), ans = max(ans, dp[k]);
		}
	}

	ans.erase(ans.begin());
	cout << ans;
}
