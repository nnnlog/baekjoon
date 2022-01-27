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

int dfs(int u) {
	vi vec;
	for (int v : graph[u]) vec.emplace_back(dfs(v));
	if (vec.empty()) return 0;
	sort(all(vec), greater<>());
	for (int i = 0; i < vec.size(); i++) vec[i] += i + 1;
	return *max_element(all(vec));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	graph.resize(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (i) graph[a].push_back(i);
	}

	cout << dfs(0);
}
