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

	pii S, E;

	int n, m; cin >> n >> m;
	vi UF(n * m);
	vector<vi> vis(n, vi(m, -1));
	vector<vpii> step(n * m);
	queue<pii> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			if (c == '+') vis[i][j] = 0, step[0].emplace_back(i, j), q.emplace(i, j);
			if (c == 'V') S = {i, j};
			if (c == 'J') E = {i, j};
		}

	while (!q.empty()) {
		pii front = q.front();
		q.pop();

		for (const auto &[dx, dy] : vpii{
			{-1, 0},
			{0, -1},
			{1, 0},
			{0, 1}
		}) {
			int x = front.first + dx, y = front.second + dy;
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (vis[x][y] != -1) continue;
			int k = vis[front.first][front.second] + 1;
			step[k].emplace_back(x, y);
			vis[x][y] = k;
			q.emplace(x, y);
		}
	}

	iota(all(UF), 0);
	auto id = [&](int x, int y) {
		return x * m + y;
	};
	function<int(int)> find = [&](int a) {
		return UF[a] = a == UF[a] ? a : find(UF[a]);
	};
	function<void(int, int)> merge = [&](int a, int b) {
		a = find(a), b = find(b);
		if (a != b) UF[a] = b;
	};
	for (int i = step.size() - 1; i >= 0; --i) {
		for (const auto &[a, b] : step[i]) {
			for (const auto &[dx, dy] : vpii{
				{-1, 0},
				{0, -1},
				{1, 0},
				{0, 1}
			}) {
				int x = a + dx, y = b + dy;
				if (x < 0 || y < 0 || x >= n || y >= m) continue;
				if (vis[x][y] >= i) merge(id(x, y), id(a, b));
			}
		}
		if (find(id(S.first, S.second)) == find(id(E.first, E.second))) {
			cout << i;
			return 0;
		}
	}
}
