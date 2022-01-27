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

	ll m, n;
	cin >> m >> n;
	vl vec(n);
	for (auto &i : vec) cin >> i;
	ll l = 0, r = 2 * 1e9;
	while (l < r) {
		ll mid = (l + r) >> 1;
		ll cnt = 0;
		for (auto i : vec) cnt += max(0LL, i - mid);
		if (cnt <= m) r = mid;
		else l = mid + 1;
	}
	ll mid = (l + r) >> 1;
	for (auto &i : vec) m -= max(0LL, i - mid), i = min(i, mid);
	sort(all(vec), greater<>());
	while (m && reduce(all(vec)))
		for (auto &i : vec)
			if (m) {
				if (i) --i, --m;
			} else break;
	ll ans = 0;
	for (auto &i : vec) ans += i * i;
	cout << ans;
}
