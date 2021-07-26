#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

vector<pii> graph[100001];
vl vis(100001);

void dfs(int a, ll c) {
	for (const auto &nxt : graph[a]) {
		if (!vis[nxt.first]) {
			vis[nxt.first] = c + (ll)nxt.second;
			dfs(nxt.first, vis[nxt.first]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int v;
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int t;
		cin >> t;
		while (1) {
			int a;
			cin >> a;
			if (a != -1) {
				int b;
				cin >> b;
				graph[t].emplace_back(a, b);
				//graph[a].emplace_back(i, b);
			} else break;
		}
	}

	//vis[1] = 1;
	dfs(1, 0);
	ll mx = -1, sel = -1;
	for (int i = 1; i <= v; i++)
		if (mx < vis[i]) {
			mx = vis[i];
			sel = i;
		}

	vis.assign(100001, 0);

	//vis[sel] = 1;
	dfs(sel, 0);
	mx = -1;
	for (int i = 1; i <= v; i++) if (i != sel) mx = max(mx, vis[i]);

	cout << mx;
}
