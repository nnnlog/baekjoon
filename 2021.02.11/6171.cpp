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

ld intersect(pll a, pll b) {
	return (ld) (b.second - a.second) / (a.first - b.first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	//vector<pll> vec(n + 1);
	auto cmp = [](const pll a, const pll &b) {
		return a.first != b.first ? a.first > b.first : a.second > b.second;
	};
	set<pll, decltype(cmp)> s(cmp);
	vl dp(n + 1);
	//vpll tmp(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		s.insert({a, b});
		/*
		tmp[i].first = a;
		tmp[i].second = b;
		 */
	}

	/*
for (int i = 1; i <= n; i++) {
	dp[i] = 1e18;
	ll mx_w = tmp[i].first, mx_h = tmp[i].second;
	for (int j = i - 1; j >= 0; j--)
		mx_w = max(mx_w, tmp[j + 1].first),
		mx_h = max(mx_h, tmp[j + 1].second),
		dp[i] = min(dp[i], dp[j] + mx_w * mx_h);
}
cout << dp[n] << "\n";

		 */
	vpll vec;
	int last = 0;
	for (const auto &[a, b] : s) {
		if (last >= b) continue;
		last = b;
		vec.emplace_back(a, b);
		//cout << "ins " << a << " " << b << "\n";
	}
	vec.emplace_back(0, 0);
	reverse(all(vec));

	vector<pair<ld, pll>> graph;
	for (int i = 1; i < vec.size(); i++) {
		ld x = -1e18;
		pll func = {vec[i].second, dp[i - 1]};
		while (!graph.empty()) {
			x = intersect(func, graph.back().second);
			if (graph.back().first < x) break;
			graph.pop_back();
		}
		graph.emplace_back(x, func);
		//for (const auto &[a, b] : graph) cout << a << " " << b.first << "*x + " << b.second << "\n";

		auto it = upper_bound(all(graph), pair<ld, pll>(vec[i].first, {-1e18, -1e18}));
		--it;
		dp[i] = it->second.first * vec[i].first + it->second.second;
		//cout << i << " " << dp[i] << "\n";
	}

	cout << dp[vec.size() - 1];
}
