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

struct A{
	int p, f, s, v, c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	int mp, mf, ms, mv; cin >> mp >> mf >> ms >> mv;
	vector<A> vec(n);
	for (auto &a : vec) cin >> a.p >> a.f >> a.s >> a.v >> a.c;
	int cost = 1e9;
	vi ans;
	for (int i = 0; i < 1 << n; i++) {
		vi selc;
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) selc.push_back(j);
		int sum = 0, p = 0, f = 0, s = 0, v = 0;
		for (const auto &j : selc) {
			A a = vec[j];
			sum += a.c;
			p += a.p;
			f += a.f;
			s += a.s;
			v += a.v;
		}
		if (mp <= p && mf <= f && ms <= s && mv <= v) {
			if (cost > sum) cost = sum, ans.swap(selc);
			else if (cost == sum) {
				for (int j = 0; j < min(selc.size(), ans.size()); j++) {
					if (selc[j] != ans[j]) {
						if (selc[j] < ans[j]) ans.swap(selc);
						goto ok;
					}
				}
				if (selc.size() < ans.size()) ans.swap(selc);
				ok:;
			}
		}
	}
	if (cost == 1e9) cout << -1;
	else {
		cout << cost << "\n";
		for (const auto &i : ans) cout << i + 1 << " ";
	}
}
