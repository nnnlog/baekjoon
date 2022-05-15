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

vi path, save;
vector<vi> graph;

void dfs(int u, int prv, int goal) {
	path.push_back(u);
	if (goal == u) save = path;
	else for (int v : graph[u]) if (v != prv) dfs(v, u, goal);
	path.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;

	int x, y, z; cin >> x >> y >> z;

	graph.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(x, 0, y);
	vi A = save;
	A.pop_back();

	dfs(y, 0, z);
	vi B = save;

	vi final;
	for (int i : A) final.push_back(i);
	for (int i : B) final.push_back(i);

	vi cnt(n + 1), skip(n + 1);
	int curr = 0;
	for (int i : final) curr += cnt[i]++ == 0;

	ll ans = 0;
	for (int i : final) {
		--curr;
		if (!skip[i]) {
			ans += curr;
//			cout << i << " " << curr << "\n";
		}
//		else cout << i << " 0\n";
		if (cnt[i]-- == 2) curr++, skip[i] = 1;
	}

	cout << ans;
}
