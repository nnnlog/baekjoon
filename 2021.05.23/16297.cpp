#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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

	int n, m; cin >> n >> m;
	vld vec(n), dp(n);
	for (auto &i : vec) cin >> i;
	vector<vi> graph(n);
	while (m--) {
		int a, b; cin >> a >> b;
		graph[b].push_back(a);
	}
	function<void(int)> solve = [&](int u) -> void {
		for (const auto &v : graph[u]) {
			ld nxt = max(dp[u], dp[u] / 2 + vec[v]);
			if (nxt > dp[v]) {
				dp[v] = nxt;
				solve(v);
			}
		}
	};
	while (n--) if (!dp[n]) dp[n] = vec[n], solve(n);
	cout << fixed;
	cout.precision(15);
	cout << dp[0];
}
