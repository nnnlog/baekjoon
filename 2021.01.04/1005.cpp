#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;

		vi cost(n), ans(n + 1);
		for (auto &i : cost) cin >> i;
		cost.insert(cost.begin(), 0);
		//ans = cost;

		vector<vi> graph(n + 1);
		vi in(n + 1);
		while (k--) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			in[b]++;
		}

		priority_queue<int> pq;
		for (int i = 1; i <= n; i++)
			if (!in[i]) pq.push(i), ans[i] = cost[i];

		while (!pq.empty()) {
			auto v = pq.top(); pq.pop();
			for (const auto &nxt : graph[v]) {
				if (--in[nxt] == 0) {
					pq.push(nxt);
				}
				ans[nxt] = max(ans[nxt], cost[nxt] + ans[v]);
			}
		}

		int a; cin >> a;
		cout << ans[a] << "\n";
	}
}
