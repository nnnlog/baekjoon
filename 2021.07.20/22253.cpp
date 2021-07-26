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

ll mod = 1e9 + 7;

vi val, vis;
vector<vi> graph;
ll ans;

vl P(10);

void dfs(int u) {
	auto org = P;
	int child = 0;
	for (const auto &v : graph[u]) {
		if (vis[v]) continue;
		vis[v] = 1;
		++child;
		for (int i = val[v]; i >= 0; i--) P[val[v]] += P[i], P[val[v]] %= mod;
		++P[val[v]];
		P[val[v]] %= mod;
		dfs(v);
		P = org;
	}
	if (!child) ans += reduce(all(P));
	else ans -= ((reduce(all(P)) % mod) * (child - 1) % mod);
	while (ans < 0) ans += mod;
	ans %= mod;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vis.resize(n + 1);
	val.resize(n + 1);
	graph.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vis[1] = 1;
	P[val[1]] = 1;
	dfs(1);
	cout << ans;
}
