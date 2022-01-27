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
	vl vec(n);
	for (auto &i : vec) cin >> i;
	sort(all(vec));
	auto solve = [&](ll k) {
		ll ret = 0;
		for (int i = 1; i < n; i++) ret += max(0LL, abs(vec[i] - i * k));
		return ret;
	};
	ll l = 1, r = vec.back();
	while (l < r) {
		ll mid = (l + r) >> 1;
		ll a = solve(mid - 1), b = solve(mid), c = solve(mid + 1);
		if (a == b || b == c) {
			cout << a;
			return 0;
		}
		if (a > b && b < c) {
			cout << b;
			return 0;
		}
		if (a > b && b > c) l = mid + 1;
		else r = mid - 1;
	}
	cout << solve((l + r) >> 1);
}
