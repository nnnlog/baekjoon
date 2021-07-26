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
	vector<pair<ll, pll>> vec(n);
	for (auto &[a, bc] : vec) cin >> a >> bc.second >> bc.first;
	auto solve = [&](ll limit) {
		ll ret = 0;
		for (auto [a, bc] : vec) if (a <= min(bc.second, limit)) ret += max(0LL, (min(bc.second, limit) - a) / bc.first + 1);
		return ret;
	};
	ll l = 0, r = 1LL << 32;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (solve(mid) % 2) r = mid;
		else l = mid + 1;
	}
	if (solve(r) % 2) cout << r << " " << solve(r) - solve(r - 1);
	else cout << "NOTHING";
}
