#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9;

struct INFO {
	int u, t, money;

	bool operator<(const INFO &a) const {
		return t < a.t && money < a.money;
	}
	bool operator>(const INFO &a) const {
		return t > a.t && money > a.money;
	}
};

vector<INFO> road[101], vis(101, INFO{0, INF, INF});
int n, t, m;

int solve(INFO info) {
	if (vis[info.u] < info) return vis[info.u].money;
	if (info.u == n) return info.money;

	//cout << info.u << "\n";

	int ans = INF;
	for (const auto &i : road[info.u]) {
		//cout << i.u << "\n";
		INFO new_info = i;
		new_info.t = info.t + i.t;
		new_info.money = info.money + i.money;

		if (new_info.t > t) continue;
		if (new_info.money > m) continue;
		//cout << i.u << " " << new_info.t << " " << new_info.money << "\n";
		//if (new_info < vis[i.u]) {
			vis[i.u] = new_info;
			ans = min(ans, solve(new_info));
		//}
	}

	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int l;
	cin >> n >> t >> m >> l;
	while (l--) {
		int u, v, w_t, w_m;
		cin >> u >> v >> w_t >> w_m;
		road[u].push_back(INFO{v, w_t, w_m});
		road[v].push_back(INFO{u, w_t, w_m});
	}

	int ans = solve(INFO{1, 0, 0});
	cout << (ans == INF ? -1 : ans);
}
