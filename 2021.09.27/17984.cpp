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

void dfs(int u, int prv, int cnt) {
	int child = graph[u].size() - (u > 0);

	int before = child / 2;
	int after = child / 2;
	if (child % 2) {
		if (cnt <= 0) ++after;
		else ++before;
	}
	while (before--) {
		int v = graph[u].back();
		graph[u].pop_back();
		if (v == prv) {
			++before;
			continue;
		}
		dfs(v, u, 1);
	}
	cout << u << " ";
	while (after--) {
		int v = graph[u].back();
		graph[u].pop_back();
		if (v == prv) {
			++after;
			continue;
		}
		dfs(v, u, -1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	graph.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, -1, 0);
}
