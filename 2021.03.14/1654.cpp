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

	ll k, n;
	cin >> k >> n;
	vl vec(k);
	for (auto &i : vec) cin >> i;
	ll l = 1, r = LLONG_MAX;
	while (l < r) {
		ull mid = ((ull)l + r) >> 1;
		ll cnt = 0;
		for (const auto &i : vec) cnt += i / mid;
		//cout << l << " " << r << " " << cnt << "\n";
		if (cnt >= n) {
			if (l == mid) break;
			l = mid;
		} else {
			if (r == mid) break;
			r = mid;
		}
	}

	cout << (l + r >> 1);
}
