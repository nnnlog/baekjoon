#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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

int mod = 1e9 + 7, mod2 = 1e9 + 9;
struct Hashing {
	ll p, m;
	vl H, B;
	void init(vl &vec) {
		H.resize(vec.size()), B.resize(vec.size());
		B[0] = 1;
		for (int i = 1; i < vec.size(); i++) {
			H[i] = (H[i - 1] * p + vec[i]) % m;
			B[i] = (B[i - 1] * p) % m;
		}
	}
	ll substr(int l, int r) {
		ll ret = H[r] - (B[r - l + 1] * H[l - 1]) % m;
		if (ret < 0) ret += m;
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	vl vec(n + 1);
	for (auto &i : vec | drop(1)) cin >> i;

	Hashing A{1'214'864, mod}, B{1'943'729, mod2};
	A.init(vec), B.init(vec);

	auto solve = [&](int len) {
		ll cnt = 1, big = 0;
		map<pll, int> used;
		for (int i = 1; i <= len; i++) {
			cnt *= m;
			if (cnt > n - len + 1) big = 1;
			cnt %= mod;
		}
		for (int i = 1; i + len - 1 <= n; i++) used[{A.substr(i, i + len - 1), B.substr(i, i + len - 1)}] = 1;
		return (cnt - ll(used.size()) + (big ? mod : 0)) % mod;
	};

	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (solve(mid) <= 0) l = mid + 1;
		else r = mid;
	}
	cout << l << " " << solve(l);
}
