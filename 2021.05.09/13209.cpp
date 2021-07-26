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

vi depth;
vector<vi> graph, child;

void dfs(int a, int d) {
	for (const auto &nxt : graph[a]) if (!depth[nxt]) depth[nxt] = d, child[a].push_back(nxt), dfs(nxt, d + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		depth.assign(n + 1, 0), graph.assign(n + 1, vi()), child.assign(n + 1, vi());
		vl cnt(n + 1);
		for (auto &i : cnt | drop(1)) cin >> i;
		for (int i = 1; i < n; i++) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		depth[1] = 1;
		dfs(1, 2);

		priority_queue<pii> origin;
		for (int i = 1; i <= n; i++) if (!child[i].empty()) origin.emplace(depth[i], i);

		ll l = *max_element(all(cnt)), r = reduce(all(cnt));
		while (l < r) {
			ll mid = (l + r) >> 1;
			auto pq = origin;
			auto sum = cnt;
			ll cut = 0;
			while (!pq.empty()) {
				int u = pq.top().second;
				pq.pop();
				priority_queue<ll, vl, greater<>> ok;
				for (const auto &i : child[u]) ok.push(sum[i]);
				while (!ok.empty()) {
					ll top = ok.top();
					if (sum[u] + top > mid) break;
					sum[u] += top;
					ok.pop();
				}
				cut += ok.size();
			}
			if (cut > k) l = mid + 1;
			else r = mid;
		}
		cout << l << "\n";
	}
}
