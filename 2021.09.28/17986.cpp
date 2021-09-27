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

vector<vi> graph;
vpii vec;
vi par;

void dfs(int u, int prv) {
	for (int v : graph[u]) if (prv != v) dfs(v, par[v] = u);
}

vi UF;
vpll save;

int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}
void merge(int sub, int parent) {
	sub = find(sub), parent = find(parent);
	if (sub != parent) UF[sub] = parent, save[parent].first += save[sub].first, save[parent].second += save[sub].second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	graph.resize(n);
	vec.resize(n);
	par.resize(n);
	for (auto &[a, _]: vec) cin >> a;
	for (auto &[_, b]: vec) cin >> b;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[--a].push_back(--b);
		graph[b].push_back(a);
	}

	UF.resize(n), save.resize(n);
	iota(all(UF), 0);

	dfs(0, 0);

	priority_queue<pair<ld, int>> pq;
	for (int i = 0; i < n; i++) pq.emplace(ld(vec[i].first) / vec[i].second, i), save[i] = vec[i];
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		int u = top.second;
		if (find(u) != u) continue;
		if (ld(save[u].first) / save[u].second != top.first) continue;
		if (u == 0) {
			cout.precision(15);
			cout << fixed;
			cout << top.first;
			return 0;
		}
		merge(u, par[u]);
		u = find(u);
		pq.emplace(ld(save[u].first) / save[u].second, u);
	}
}
