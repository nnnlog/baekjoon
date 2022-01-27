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

	int n; cin >> n;
	vector<pair<int, pii>> vec;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int a; cin >> a;
			if (i != j) vec.emplace_back(a, pii(i, j));
		}

	vector<vi> dist(n + 1, vi(n + 1, 1e9));
	auto gen = [&]() {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	};

	sort(all(vec));

	int ans = 0;

	for (const auto &[w, p] : vec) {
		int x = p.first, y = p.second;
		if (dist[x][y] < w) {
			cout << -1;
			return 0;
		}
		if (dist[x][y] != w) ans += dist[x][y] = dist[y][x] = w;
		gen();
	}

	cout << ans;
}
