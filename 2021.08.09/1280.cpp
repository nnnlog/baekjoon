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

ll mod = 1'000'000'007;
vpll seg;

pll sum(pll A, pll B) {
	return {(A.first + B.first) % mod, A.second + B.second};
}

pll upd(int node, int start, int end, ll k) {
	auto &ret = seg[node];
	if (!(start <= k && k <= end)) return ret;
	if (start == end) return ret = sum(ret, {k, 1});
	else {
		int mid = (start + end) >> 1;
		return ret = sum(upd(node * 2, start, mid, k), upd(node * 2 + 1, mid + 1, end, k));
	}
}

pll qry(int node, int start, int end, int l, int r) {
	if (end < l || start > r) return {0, 0};
	if (l <= start && end <= r) return seg[node];
	else {
		int mid = (start + end) >> 1;
		return sum(qry(node * 2, start, mid, l, r), qry(node * 2 + 1, mid + 1, end, l, r));
	}
}

int MX = 2e5 + 10;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	seg.assign(MX * 4, pll(0, 0));

	int n;
	cin >> n;
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		upd(1, 0, MX, a);
		if (i) {
			ll cnt = 0;
			auto L = qry(1, 0, MX, 0, a);
			//cout << "0 " << a << " : " << L.first << " " << L.second << "\n";
			cnt += a * L.second - L.first;
			auto R = qry(1, 0, MX, a, MX);
			//cout << a << " 200001 : " << R.first << " " << R.second << "\n";
			cnt += R.first - a * R.second;
			cnt %= mod;
			if (cnt < 0) cnt += mod;
			ans *= cnt;
			ans %= mod;
		}
	}
	cout << ans;
}
