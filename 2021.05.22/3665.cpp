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

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vi vec(n), in(n);
		for (auto &i : vec) cin >> i, --i;
		vector<vi> graph(n, vi(n));
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) graph[vec[i]][vec[j]] = 1, ++in[vec[j]];
		int m; cin >> m;
		while (m--) {
			int a, b; cin >> a >> b;
			--a, --b;
			if (!graph[a][b]) swap(a, b);
			graph[a][b] = 0;
			graph[b][a] = 1;
			--in[b], ++in[a];
		}
		queue<int> q;
		for (int i = 0; i < n; i++) if (!in[i]) q.push(i);
		vi ans;
		while (!q.empty()) {
			int curr = q.front(); q.pop();
			ans.push_back(curr);
			for (int i = 0; i < n; i++) if (graph[curr][i] && !--in[i]) q.push(i);
		}
		if (reduce(all(in))) cout << "IMPOSSIBLE";
		else for (auto i : ans) cout << i + 1 << " ";
		cout << "\n";
	}
}
