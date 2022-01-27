#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vi in(n + 1), cost(n + 1), ans(n + 1);
	vector<vi> graph(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cost[i] >> in[i];
		int c = in[i];
		while (c--) {
			int a;
			cin >> a;
			graph[a].push_back(i);
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!in[i]) q.push(i), ans[i] += cost[i];

	while (!q.empty()) {
		auto f = q.front(); q.pop();
		for (const auto &nxt : graph[f]) {
			if (!(--in[nxt])) q.push(nxt);
			ans[nxt] = max(ans[nxt], cost[nxt] + ans[f]);
		}
	}

	cout << *max_element(all(ans));
}
