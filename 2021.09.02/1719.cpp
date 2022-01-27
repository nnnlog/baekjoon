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

	int n, m;
	cin >> n >> m;
	vector<vi> dist(n + 1, vi(n + 1, 1e9)), graph(n + 1, vi(n + 1, 1e9)), ans(n + 1, vi(n + 1));
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		dist[a][b] = dist[b][a] = graph[a][b] = graph[b][a] = w;
		ans[a][b] = b;
		ans[b][a] = a;
	}
	for (int v = 1; v <= n; v++)
		for (int i = 1; i <= n; i++) {
			dist[i][i] = 0;
			for (int j = 1; j <= n; j++)
				if (dist[i][j] > dist[i][v] + dist[v][j]) dist[i][j] = dist[i][v] + dist[v][j], ans[i][j] = ans[i][v];
		}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (i == j) cout << "- ";
			else cout << ans[i][j] << " ";
		cout << "\n";
	}
}
