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

	int n;
	cin >> n;
	vl vec(n);
	for (auto &i : vec) cin >> i;
	sort(all(vec));
	ll l = 1, r = 1e10, S = ceil((ld)n * (n - 1) / 4);
	while (l < r) {
		ll mid = (l + r) >> 1, cnt = 0;
		for (ll i = 0; i < n; i++) {
			auto it = --upper_bound(vec.begin() + i + 1, vec.end(), mid - vec[i]);
			cnt += max(0LL, it - vec.begin() - i);
		}
		//cout << mid << " " << cnt << "\n";
		if (cnt >= S) {
			if (r == mid) break;
			r = mid;
		} else l = mid + 1;
	}
	cout << ((l + r) >> 1);
}
