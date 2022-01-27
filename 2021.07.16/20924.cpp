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

vector<vpii> graph;
vi vis;
int ans0 = -1, ans1;

void dfs(int u, int len, int ans) {
	ans1 = max(ans1, ans);
	int child = 0;
	for (const auto &[v, w] : graph[u])
		if (!vis[v]) ++child;
	if (ans0 == -1 && (child > 1 || !child)) ans0 = len;
	for (const auto &[v, w] : graph[u])
		if (!vis[v]) {
			++child;
			vis[v] = 1;
			dfs(v, len + w, ans + (ans0 >= 0 ? w : 0));
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, k; cin >> n >> k;
	graph.resize(n + 1), vis.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b, w; cin >> a >> b >> w;
		graph[a].emplace_back(b, w);
		graph[b].emplace_back(a, w);
	}
	vis[k] = 1;
	dfs(k, 0, 0);
	cout << ans0 << " " << ans1;
}
