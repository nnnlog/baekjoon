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
		{0, -1},
		{1, 0},
		{0, 1},
		{-1, 0}
};

int dist[22500][1501];
vector<pair<int, pii>> graph[22500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int r, c, k;
	cin >> r >> c >> k >> ws;

	auto id = [&](int x, int y) {
		return x * c + y;
	};

	auto add = [&](int idx, int x, int y, pii w) {
		if (x < 0 || y < 0 || x >= r || y >= c) return;
		graph[idx].push_back({id(x, y), w});
	};
	for (int i = 0; i < r; i++) {
		string s;
		getline(cin, s);
		for (int j = 0; j < c; j++) {
			if (s[j] == 'L') s[j] = 0;
			else if (s[j] == 'D') s[j] = 1;
			else if (s[j] == 'R') s[j] = 2;
			else s[j] = 3;
			int idx = id(i, j);
			for (int l = 0; l < 4; l++) {
				add(idx, i + dxdy[(s[j] + l) % 4].first, j + dxdy[(s[j] + l) % 4].second, {l, 0});
				add(idx, i + dxdy[(s[j] + l * 3) % 4].first, j + dxdy[(s[j] + l * 3) % 4].second, {0, l});
			}
		}
	}

	memset(dist, 0x7f7f7f7f, sizeof dist);
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
	pq.push({dist[0][0] = 0, {0, 0}});
	auto push = [&](int idx, int l, int r) {
		if (l > k || r > k) return;
		if (dist[idx][l] > r) dist[idx][l] = r, pq.push({r, {l, idx}});
	};
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		if (top.second.second == r * c - 1) {
			cout << "Yes";
			return 0;
		}
		for (const auto &[nxt, w] : graph[top.second.second]) push(nxt, top.second.first + w.first, top.first + w.second);
	}
	cout << "No";
}
