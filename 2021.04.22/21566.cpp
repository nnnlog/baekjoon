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

int n;
set<int> child[1001];
vi in;
vector<vi> graph;
set<int> origin[1001];

vi vis;
void dfs2(int a, int c) {
	for (const auto &nxt : graph[a]) {
		if (!vis[nxt]) {
			vis[nxt] = c + 1;
			dfs2(nxt, vis[nxt]);
		}
	}
}

int get() {
	for (auto &v : graph) v.clear();
	for (int i = 1; i <= n; i++)
		for (const auto &j : origin[i])
			graph[i].emplace_back(j), graph[j].emplace_back(i);

	vis.assign(n + 1, 0);
	dfs2(1, 0);
	int d = max_element(all(vis)) - vis.begin();
	vis.assign(n + 1, 0);
	dfs2(d, 0);
	return *max_element(all(vis));
}

void dfs(int a) {
	for (const auto &nxt : graph[a]) {
		if (in[nxt]) continue;
		in[nxt] = 1;
		child[a].insert(nxt);
		origin[a].insert(nxt);
		dfs(nxt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	in.resize(n + 1);
	graph.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		in[a]++, in[b]++;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	int root = 0;
	queue<int> pq;
	for (int i = 1; i <= n; i++)
		if (in[i] == 1) pq.push(i);
	while (!pq.empty()) {
		auto top = pq.front(); pq.pop();
		for (const auto &nxt : graph[top]) {
			if (--in[nxt] == 1) pq.push(nxt);
		}
		root = top;
	}
//	cout << "root " << root << "\n";

	in.assign(n + 1, 0);
	in[root] = 1;
	dfs(root);

	vector<pair<pii, pii>> ans;
	while (!child[root].empty()) {
		int A = root;
		int B = *child[A].begin();
		if (child[B].empty()) {
			child[A].erase(B);
			continue;
		}
		int C = *child[B].begin();
		if (child[C].empty()) {
			child[B].erase(C);
			continue;
		}
		int D = *child[C].begin();
		child[A].erase(B);
		child[B].erase(C);
		child[C].erase(D);

		child[A].insert(C), child[A].insert(D);
		child[D].insert(B);

		for (const auto &ch : origin[B])
			if (ch != C) child[B].insert(ch);

		ans.emplace_back(pii(A, B), pii(C, D));

		origin[A].erase(B);
		origin[B].erase(C);
		origin[C].erase(D);

		origin[A].insert(C), origin[A].insert(D);
		origin[D].insert(B);
/*
		for (int i = 1; i <= n; i++)
			for (const auto &j : origin[i]) cout << i << "->" << j << "\n";
		cout << A << " " << B << " " << C << " " << D << endl;

		cout << get() << endl;
*/
	}

//	cout << "final " << get() << "\n";
	/*
	for (int i = 1; i <= n; i++)
		for (const auto &j : origin[i]) cout << i << "->" << j << "\n";
*/
	cout << ans.size() << "\n";
	for (const auto &i : ans) cout << i.first.first << " " << i.first.second << " " << i.second.first << " " << i.second.second << "\n";
}
