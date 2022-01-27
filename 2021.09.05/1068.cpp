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

int skip;
vector<vi> graph;
int dfs(int u, int prv) {
	int cnt = 0;
	for (const auto &v : graph[u]) {
		if (v == prv) continue;
		cnt += dfs(v, u);
	}
	return max(int(skip != u), cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	graph.resize(n);
	int root;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == -1) root = i;
		else graph[a].push_back(i);
	}
	cin >> skip;
	graph[skip].clear();
	cout << dfs(root, -1);
}
