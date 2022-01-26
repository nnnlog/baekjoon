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

	for (int tc = 1;; tc++) {
		vector<vi> graph(20);

		vi in(20, 0);
		vi use(20);
		int fail = 0, k = 0;
		while (1) {
			int a, b;
			cin >> a >> b;
			if (a == -1 && b == -1) return 0;
			if (!a && !b) break;
			assert(a < 20 && b < 20);
			graph[a].push_back(b);
			in[b]++;
			use[a] = use[b] = 1;
			if (a == b) fail = 1;
			k++;
		}

		int root = -1;
		vi vis(20, 0);
		function<void(int)> dfs = [&](int u) {
			if (fail) return;
			for (int v: graph[u]) {
				if (vis[v]) {
					fail = 1;
					return;
				}
				vis[v] = 1;
				dfs(v);
			}
		};

		if (!k) goto bye;

		for (int i = 0; i < 20; i++) {
			if (!in[i] && use[i]) {
				if (root != -1) {
					fail = 1;
					goto bye;
				}
				root = i;
			}
		}
		if (root == -1) {
			fail = 1;
			goto bye;
		}
		if (!fail) vis[root] = 1;
		dfs(root);

		for (int i = 0; i < 20; i++) {
			if (use[i] && !vis[i]) {
				fail = 1;
				break;
			}
		}

		bye:;
		if (fail) cout << "Case " << tc << " is not a tree.\n";
		else cout << "Case " << tc << " is a tree.\n";
	}
}
