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

vi graph[100001], depth, parent;

void dfs(int a, int d) {
	depth[a] = d++;
	for (const auto &nxt : graph[a]) if (depth[nxt] > d) dfs(nxt, d), parent[nxt] = a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	depth.assign(n + 1, 1e9);
	parent.assign(n + 1, 1e9);
	parent[1] = 1;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
		if (a == b) {
			cout << "0";
			return 0;
		}
	}
	dfs(1, 1);
	int prv = 0;
	queue<int> par, tmp;
	while (n--) {
		int a; cin >> a;
		if (prv > depth[a]) {
			cout << "0";
			return 0;
		}
		if (prv != depth[a]) par = tmp, tmp = {};
		tmp.push(a);
		if (a == 1) continue;
		int p = parent[a];
		while (!par.empty() && par.front() != p) par.pop();
		if (par.empty()) {
			//cout << "fail " << a << "\n";
			cout << "0";
			return 0;
		}

		prv = depth[a];
	}

	cout << "1";
}
