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

	int n, k; cin >> n >> k;
	vpii vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i].second;
	for (int i = 0; i < n; i++) cin >> vec[i].first;
	sort(all(vec));
	vector<vi> use(n + 1);
	set<pii> cnt;
	ll sum = 0;
	for (int i = 0; i < k; i++) use[vec[i].second].push_back(vec[i].first), sum += vec[i].first;
	for (auto &v : use) sort(all(v));
	for (int i = 1; i <= n; i++) cnt.emplace(use[i].size(), i);
	priority_queue<pii, vpii, greater<>> pq;
	for (int i = k; i < n; i++) pq.push(vec[i]);
	int f = 0;
	vl ans(n);
	ans[n - 1] = sum;
	for (int L = n - 1; L >= 1; --L) {
		if (f) {
			ans[L - 1] = -1;
			continue;
		}
		int c = 0;
		for (auto it = cnt.lower_bound({L + 1, 0}); it != cnt.end();) {
			auto nxt = next(it);
			++c;
			sum -= use[it->second].back();
			cnt.erase({use[it->second].size(), it->second});
			use[it->second].pop_back();
			cnt.insert({use[it->second].size(), it->second});

			it = nxt;
		}
		while (!pq.empty() && c) {
			auto top = pq.top(); pq.pop();
			if (use[top.second].size() >= L) continue;
			--c;
			cnt.erase({use[top.second].size(), top.second});
			use[top.second].push_back(top.first);
			sum += top.first;
			cnt.insert({use[top.second].size(), top.second});
		}
		if (c) ans[L - 1] = -1, f = 1;
		else ans[L - 1] = sum;
	}
	for (ll i : ans) cout << i << " ";
}
