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
	vector<vi> dist(n + 1, vi(n + 1, 1e9));
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		dist[a][b] = c;
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int t; cin >> t;
	vi vec(t);
	for (int &i : vec) cin >> i;
	int tm = 1e9;
	vi ans;
	for (int i = 1; i <= n; i++) {
		int a = 0;
		for (int k : vec) a = max(a, dist[k][i] + dist[i][k]);
		if (tm > a) ans.clear(), tm = a;
		if (tm == a) ans.push_back(i);
	}
	for (int i : ans) cout << i << " ";
}
