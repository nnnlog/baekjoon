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
	vector<vi> graph(n + 1), dist(n + 1, vi(n + 1, 1e9));
	while (m--) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = dist[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			dist[i][i] = 0;
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = 1e9;
	pii comb = {};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int sum = 0;
			for (int a = 1; a <= n; a++) {
				sum += min(dist[a][i], dist[a][j]);
			}
			//cout << i << " " << j << " " << sum << "\n";
			if (sum < ans) comb = {min(i, j), max(i, j)};
			else if (sum == ans) comb = min(comb, {i, j});
			ans = min(ans, sum);
		}
	}

	cout << comb.first << " " << comb.second << " " << ans * 2;
}
