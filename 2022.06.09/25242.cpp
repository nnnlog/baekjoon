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

	int n, q;
	cin >> n >> q;

	int idx = 0;
	unordered_map<string, int> station_id;
	vi station_cnt(2e5 + 1);
	vector<map<int, int>> lines_of_station(2e5 + 1);
	vector<vi> station_in_line(n), transfer_station_pos_in_line(n);
	vector<map<int, int>> station_position_in_line(n);
	vector<vi> graph(2e5 + 1);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		int prv = -1;
		while (a--) {
			string x;
			cin >> x;

			if (!station_id[x]) station_id[x] = ++idx;
			int id = station_id[x];

			station_in_line[i].push_back(id);
			station_cnt[id]++;
			lines_of_station[id][i] = 1;

			if (prv != -1) graph[prv].push_back(id);
			graph[id].push_back(prv);
			prv = id;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < station_in_line[i].size(); j++) {
			if (station_cnt[station_in_line[i][j]] >= 2) transfer_station_pos_in_line[i].push_back(j);
			station_position_in_line[i][station_in_line[i][j]] = j;
		}
	}

	auto get_dist_when_same_line = [&](int a, int b) {
		int ret = 1e9;
		for (const auto &[line, _]: lines_of_station[a]) {
			if (lines_of_station[b].count(line)) {
				ret = min(ret, abs(station_position_in_line[line][a] - station_position_in_line[line][b]) * 2);
			}
		}
		return ret;
	};

	auto dijkstra = [&](int x) {
		vi dist(2e5 + 1, 1e9);
		priority_queue<pii, vpii, greater<>> pq;
		pq.emplace(dist[x] = 0, x);
		while (!pq.empty()) {
			auto top = pq.top();
			pq.pop();
			if (dist[top.second] < top.first) continue;
			for (const auto &v: graph[top.second]) {
				int nxt = top.first + 2;
				if (nxt < dist[v]) pq.emplace(dist[v] = nxt, v);
			}
		}
		return dist;
	};

	vector<vi> dist(2e5 + 1);

	vi transfer_station;
	for (int i = 0; i < station_cnt.size(); i++) {
		if (station_cnt[i] >= 2) transfer_station.push_back(i);
	}

	for (int i: transfer_station) {
		dist[i] = dijkstra(i);
	}

	while (q--) {
		string a, b;
		cin >> a >> b;
		int x = station_id[a], y = station_id[b];
		int line = lines_of_station[x].begin()->first;
		int ans = 1e9;
		if (!binary_search(all(transfer_station), x)) ans = get_dist_when_same_line(x, y);

		auto it = lower_bound(all(transfer_station_pos_in_line[line]), station_position_in_line[line][x]);
		if (it < transfer_station_pos_in_line[line].end()) {
			int v = station_in_line[line][*it];
			ans = min(ans, dist[v][x] + dist[v][y]);
		}
		if (it > transfer_station_pos_in_line[line].begin()) {
			--it;
			int v = station_in_line[line][*it];
			ans = min(ans, dist[v][x] + dist[v][y]);
		}

		if (ans == 1e9) ans = -1;
		cout << ans << "\n";
	}
}
