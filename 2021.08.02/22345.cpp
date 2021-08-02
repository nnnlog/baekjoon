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

	int n, q; cin >> n >> q;
	mpii cnt;
	vl ans(q);
	map<int, int> sweeping;
	while (n--) {
		int c, a; cin >> c >> a;
		cnt[a] = c;
		sweeping[a] = -1;
	}
	for (int i = 0; i < q; i++) {
		int a; cin >> a;
		sweeping[a] = i;
	}
	ll sum = 0, last = sweeping.begin()->first, L = 0, R = 0;
	for (const auto &[x, c] : cnt) {
		R += c;
		sum += ll(x - last) * c;
	}
	for (const auto &[x, qry] : sweeping) {
		sum += (x - last) * L;
		sum -= (x - last) * R;
		if (cnt.count(x)) R -= cnt[x], L += cnt[x];
		if (qry >= 0) ans[qry] = sum;
		last = x;
	}
	for (ll a : ans) cout << a << "\n";
}
