#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

vpll dp(91);

auto digit(ll k) {
	return lower_bound(all(dp), pll(k, -1))->second;
}

auto cnt(ll k) {
	return (--lower_bound(all(dp), pll(k, -1)))->first;
}

string solve(ll k) {
	//cout << k << "\n";
	if (!k) return "";
	if (k == 1) return "1";
	ll diff = digit(k) - 2 - digit(k - cnt(k) - 1);
	string ret = "10";
	while (diff--) ret += "0";
	//cout << ret << "\n";
	return ret + solve(k - cnt(k) - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	dp[1].first = dp[1].second = dp[2].first = 1;
	for (ll i = 3; i <= 90; i++) dp[i].first = dp[i - 1].first + dp[i - 2].first;
	for (ll i = 2; i <= 90; i++) dp[i].first += dp[i - 1].first, dp[i].second = i;//, cout << i << " " << dp[i].first << "\n";

	ll k; cin >> k;
	cout << solve(k);
}
