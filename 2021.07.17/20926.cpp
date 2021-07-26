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

	int r, c; cin >> c >> r;
	auto id = [&](int x, int y) {
		return x * c + y;
	};

	vector<vi> vec(r, vi(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			char a; cin >> a;
			if (a == 'T') S = {i, j};
			else if (a == 'E') E = {i, j};
			else if (a == 'R') vec[i][j] = -1; //돌
			else if (a == 'H') vec[i][j] = -2; //구멍
			else vec[i][j] = a - '0';
		}

	vi dist(r * c, 1e9);
	priority_queue<pii, vpii, greater<>> pq;
	auto push = [&](int id, int nxt) {
		if (dist[id] > nxt) pq.emplace(dist[id] = nxt, id);
	};

	pq.emplace(dist[id(S.first, S.second)] = 0, id(S.first, S.second));
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		if (dist[top.second] < top.first) continue;
		int x = top.second / c, y = top.second % c;
		{
			int sum = top.first;
			for (int i = x + 1; i < r; i++) {
				int w = vec[i][y];
				if (w == -2) break;
				if (w == -1) {
					if (x != i - 1) push(id(i - 1, y), sum);
					break;
				} else if (E == pii(i, y)) {
					push(id(i, y), sum);
					break;
				} else sum += w;
			}
		}
		{
			int sum = top.first;
			for (int i = x - 1; i >= 0; i--) {
				int w = vec[i][y];
				if (w == -2) break;
				if (w == -1) {
					if (x != i + 1) push(id(i + 1, y), sum);
					break;
				} else if (E == pii(i, y)) {
					push(id(i, y), sum);
					break;
				} else sum += w;
			}
		}
		{
			int sum = top.first;
			for (int j = y + 1; j < c; j++) {
				int w = vec[x][j];
				if (w == -2) break;
				if (w == -1) {
					if (y != j - 1) push(id(x, j - 1), sum);
					break;
				} else if (E == pii(x, j)) {
					push(id(x, j), sum);
					break;
				} else sum += w;
			}
		}
		{
			int sum = top.first;
			for (int j = y - 1; j >= 0; j--) {
				int w = vec[x][j];
				if (w == -2) break;
				if (w == -1) {
					if (y != j + 1) push(id(x, j + 1), sum);
					break;
				} else if (E == pii(x, j)) {
					push(id(x, j), sum);
					break;
				} else sum += w;
			}
		}
	}

	int ans = dist[id(E.first, E.second)];
	if (ans == 1e9) ans = -1;
	cout << ans;
}
