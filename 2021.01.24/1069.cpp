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

ll x, y, d, t, dis;
ld base;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout.precision(9);
	cout << fixed;

	cin >> x >> y >> d >> t;
	base = sqrtl(x * x + y * y);
	dis = base;
	base = base - (ll) base;

	if (d <= t) cout << base + dis;
	else {
		ll i = dis / d;
		dis %= d;
		ld ans = i * t;
		//cout << i << " " << dis << "\n";
		if (!dis && !base) cout << ans;
		else {
			ld tmp = dis + base;
			if (i) {
				tmp = min(tmp, (ld) t);
			}
			tmp = min(tmp, (ld)t + (d - dis) + (- base));
			tmp = min(tmp, (ld)2 * t);
			cout << ans + tmp;
		}
	}
}
