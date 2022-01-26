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

	int n, m; cin >> n >> m;
	vector<vpii> graph(n + 1);
	vi in(n + 1);
	while (m--) {
		int a, b, w; cin >> a >> b >> w;
		graph[a].emplace_back(b, w);
		if (b != 1) in[b]++;
	}
	queue<int> Q;
	Q.push(1);
	vi ans(n + 1), track(n + 1);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (const auto &[v, w] : graph[u]) {
			if (!--in[v]) Q.push(v);
			if (ans[v] < ans[u] + w) ans[v] = ans[u] + w, track[v] = u;
		}
	}
	cout << ans[1] << "\n";
	stack<int> p;
	p.push(1);
	for (int i = track[1]; i != 1; i = track[i]) p.push(i);
	p.push(1);
	while (!p.empty()) cout << p.top() << " ", p.pop();
}
