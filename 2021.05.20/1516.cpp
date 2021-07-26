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
	vector<vi> graph(n + 1);
	vi cnt(n + 1), ans(n + 1), build(n + 1);
	for (int i = 1; i <= n; i++) {
		int a; cin >> build[i] >> a;
		while (a > 0) {
			graph[a].push_back(i);
			++cnt[i];
			cin >> a;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) if (!cnt[i]) q.push(i), ans[i] = build[i];
	while (!q.empty()) {
		int f = q.front(); q.pop();

		for (const auto &nxt : graph[f]) {
			ans[nxt] = max(ans[nxt], ans[f]);
			if (!--cnt[nxt]) ans[nxt] += build[nxt], q.push(nxt);
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
}
