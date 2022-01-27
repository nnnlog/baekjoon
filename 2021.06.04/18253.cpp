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

vpii dxdy = {
		{-1, 0},
		{1,  0},
		{0,  -1},
		{0,  1}
};

int n, m, mp[6][100001];
ll dist[6][100001];

void dijkstra(int l, int r, int k) {
	int mid = (l + r) >> 1;
	for (int i = 1; i <= n; i++) for (int j = l; j <= r; j++) dist[i][j] = 1e18;
	priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<>> pq;
	pq.emplace(dist[k][mid] = 0, pii(k, mid));
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		if (top.first > dist[top.second.first][top.second.second]) continue;
		for (const auto &[dx, dy] : dxdy) {
			int x = top.second.first + dx, y = top.second.second + dy;
			if (x < 1 || x > n || y < l || y > r) continue;
			ll w = top.first + mp[x][y];
			if (w < dist[x][y]) {
				dist[x][y] = w;
				pq.emplace(w, pii(x, y));
			}
		}
	}
}

vector<pair<pii, pii>> vec;
vl ans;

void solve(int l, int r, vi query) {
	if (l > r || query.empty()) return;
	vi L, R;
	int mid = (l + r) >> 1;
	for (int k = 1; k <= n; k++) {
		dijkstra(l, r, k);
		for (const auto &i : query) {
			int x1 = vec[i].first.first, y1 = vec[i].first.second, x2 = vec[i].second.first, y2 = vec[i].second.second;
			ans[i] = min(ans[i], dist[x1][y1] + dist[x2][y2] + mp[k][mid]);
			if (k == 1 && !(y1 <= mid && mid <= y2)) {
				if (y1 <= mid) L.push_back(i);
				else R.push_back(i);
			}
		}
	}
	solve(l, mid - 1, L);
	solve(mid + 1, r, R);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> mp[i][j];
	int q;
	cin >> q;
	ans.assign(q, 1e18);
    vec.reserve(q);
	for (int i = 1; i <= q; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 > y2) swap(x1, x2), swap(y1, y2);
		vec.push_back({{x1, y1},
		               {x2, y2}});
	}
	vi tmp(q);
	iota(all(tmp), 0);
	solve(1, m, tmp);
	for (ll i : ans) cout << i << "\n";
}
