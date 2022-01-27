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

	int n, m;
	cin >> n >> m;
	vpii sweep;
	sweep.reserve(m * 2);
	vi cnt(n);
	int prv;
	for (int i = 0; i < m; i++) {
		int curr;
		cin >> curr;
		--curr;
		if (i) {
			int a = prv, b = curr;
			if (a > b) swap(a, b);
			--b;
			sweep.emplace_back(a, 0), sweep.emplace_back(b, 1);
		}
		prv = curr;
	}
	sort(all(sweep));
	int open = 0, k = 0, last = 0;
	for (const auto &[a, b] : sweep) {
		if (a != last) while (k < a) cnt[k++] = open;
		if (!b) ++open;
		else {
			while (k <= a) cnt[k++] = open;
			--open;
		}
		last = a;
	}
	vector<pair<ll, pll>> graph(n - 1);
	for (auto &[a, bc] : graph) cin >> a >> bc.first >> bc.second;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll x = cnt[i];
		ans += min(graph[i].first * x, graph[i].second.first * x + graph[i].second.second);
	}
	cout << ans;
}
