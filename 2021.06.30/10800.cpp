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

struct A {
	ll color, sz, idx, sum;
	bool operator< (const A &b) const {
		return sz < b.sz;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	unordered_map<int, vi> mp;
	unordered_map<int, vpii> colored_sum;
	vector<A> vec;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		mp[a].push_back(b);
		vec.push_back({
			a, b, i, b
		});
	}
	sort(all(vec));
	for (int i = 1; i < n; i++) vec[i].sum += vec[i - 1].sum;
	for (auto &[k, v] : mp) {
		sort(all(v));
		auto &tmp = colored_sum[k];
		tmp.resize(v.size());
		for (int i = 0; i < v.size(); i++) {
			if (i) tmp[i] = tmp[i - 1];
			tmp[i].second += v[i];
			tmp[i].first = v[i];
		}
	}
	vl ans(n);
	for (const auto &a : vec) {
		auto it = lower_bound(all(vec), A{.sz=a.sz});
		if (it == vec.begin()) continue;
		ans[a.idx] += (--it)->sum;
		auto it2 = lower_bound(all(colored_sum[a.color]), pii{a.sz, 0});
		if (it2 == colored_sum[a.color].begin()) continue;
		ans[a.idx] -= (--it2)->second;
	}
	for (int i : ans) cout << i << "\n";
}
