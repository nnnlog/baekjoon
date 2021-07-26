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

const ll mod = 1e9 + 7;

ll fct(int a) {
	ll ret = 1;
	for (int i = 2; i <= a; i++) ret *= i, ret %= mod;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vl dp(n + 1);
	dp[2] = 1;
	for (int i = 3; i <= n; i++) dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % mod;
	cout << fct(n) * dp.back() % mod;
}
