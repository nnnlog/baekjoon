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
		{1, 0},
		{0, -1},
		{0, 1}
};

unordered_map<char, pii> mp = {
		{'R', {0, 1}},
		{'L', {0, -1}},
		{'D', {1, 0}},
		{'U', {-1, 0}},
};
map<pii, char> rmp = {
		{{0, 1}, 'R'},
		{{0, -1}, 'L'},
		{{1, 0}, 'D'},
		{{-1, 0}, 'U'},
};

int L_dist(char c, char d) {
	vi vec = {'L', 'D', 'R', 'U'};
	int a = find(all(vec), c) - vec.begin();
	int b = find(all(vec), d) - vec.begin();
	int ret = b - a;
	if (ret < 0) ret += 4;
	return ret;
}

int R_dist(char c, char d) {
	vi vec = {'L', 'U', 'R', 'D'};
	int a = find(all(vec), c) - vec.begin();
	int b = find(all(vec), d) - vec.begin();
	int ret = b - a;
	if (ret < 0) ret += 4;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int r, c, k; cin >> r >> c >> k;
	vector<vector<char>> vec(r, vector<char>(c));
	for (auto &a : vec) for (auto &b : a) cin >> b;

	auto id = [&](int x, int y) {
		return x * c + y;
	};
	auto ext = [&](int id) {
		return pii{id / c, id % c};
	};

	vector<vi> dist(r * c, vi(k + 1, 1e9));
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
	pq.push({dist[0][0] = 0, {0, 0}});
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		pii ab = ext(top.second.first);
		int a = ab.first, b = ab.second, L = top.second.second, R = top.first;
		if (R > dist[top.second.first][L]) continue;
		int exp_a = a + mp[vec[a][b]].first, exp_b = b + mp[vec[a][b]].second;
		for (const auto &[dx, dy] : dxdy) {
			int x = a + dx, y = b + dy;
			if (x < 0 || y < 0 || x >= r || y >= c) continue;
			int idx = id(x, y);
			if (x == exp_a && y == exp_b) {
				if (dist[idx][L] > R) pq.push({dist[idx][L] = R, {idx, L}});
			} else {
				int t = L_dist(vec[a][b], rmp[{dx, dy}]);
				if (L + t <= k && dist[idx][L + t] > R) pq.push({dist[idx][L + t] = R, {idx, L + t}});
				t = R_dist(vec[a][b], rmp[{dx, dy}]);
				if (R + t <= k && dist[idx][L] > R + t) pq.push({dist[idx][L] = R + t, {idx, L}});
			}
		}
	}
	int ans = *min_element(all(dist.back()));
	cout << (ans <= k ? "Yes" : "No");
}
