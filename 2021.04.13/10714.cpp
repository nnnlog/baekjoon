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

int n;
vl vec;
vector<vl> dp;

int p(int a) {
	return (a + 1) % n;
}
int m(int a) {
	return (n + a - 1) % n;
}

ll solve(int l, int r, int c) {
	if (l == r) return c ? 0 : vec[l];
	ll &ret = dp[l][r];
	if (ret) return ret;
	int x = m(l), y = p(r);
	if (c) return ret = vec[l] > vec[r] ? solve(x, r, !c) : solve(l, y, !c);
	return ret = max(solve(x, r, !c) + vec[l], solve(l, y, !c) + vec[r]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vec.resize(n);
	dp.assign(n, vl(n));
	for (auto &i : vec) cin >> i;

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, solve(m(i), p(i), 1) + vec[i]);
	}

	cout << ans;
}
