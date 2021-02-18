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

ll R, L, B;
vl vec, sum;

pll calc(ll l, ll r) {
	ll mid = (vec[l+r>>1]);
	ll price = 0;

	auto it = lower_bound(vec.begin() + l, vec.end(), mid);
	ll idx = l+r>>1;it - vec.begin() - 1;
	if (idx >= l) {
		ll sz = (idx - l + 1) * mid;
		price += sz - (sum[idx] - sum[l - 1]);
	}
	it = upper_bound(vec.begin() + l, vec.end(), mid);
	idx = l+r>>1;it - vec.begin();
	if (idx <= r) {
		ll sz = (r - idx + 1) * mid;
		price += (sum[r] - sum[idx - 1]) - sz;
	}
	//cout << l << " " << r << " " << price << "\n";

	return {price, r - l + 1};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> L >> B;
	vec.resize(R + 1), sum.resize(R + 1);
	for (int i = 1; i <= R; i++) cin >> vec[i], sum[i] = sum[i - 1] + vec[i];

	ll ans = 0;
	for (int i = 1; i <= R; i++) {
		ll l = i, r = R + 1;
		while (l <= r && l <= R) {
			ll mid = (l + r) >> 1;
			if (calc(i, mid).first > B) r = mid - 1;
			else {
				ans = max(ans, mid - i + 1);
				l = mid + 1;
			}
		}
	}
	//for (const auto &i : vec) ans = max(ans, solve(i, L));
	cout << ans;
}
