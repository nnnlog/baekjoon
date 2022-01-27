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

	int n, m; cin >> n >> m;
	vector<vpii> graph(n + 1);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		c *= 2;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	vector<vi> A(n + 1, vi(2, 1e9));
	{
		priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<>> pq;
		A[1][0] = 0;
		pq.push({{0, 0}, 1});
		while (!pq.empty()) {
			auto top = pq.top();
			pq.pop();
			if (A[top.second][top.first.second] < top.first.first) continue;
			for (const auto &[nxt, w] : graph[top.second]) {
				int ok = top.first.first;
				if (top.first.second) ok += w * 2;
				else ok += w / 2;
				if (A[nxt][!top.first.second] > ok) {
					A[nxt][!top.first.second] = ok;
					pq.push({{ok, !top.first.second}, nxt});
				}
			}
		}
	}
	vi B(n + 1, 1e9);
	{
		priority_queue<pii, vpii, greater<>> pq;
		B[1] = 0;
		pq.push({0, 1});
		while (!pq.empty()) {
			auto top = pq.top();
			pq.pop();
			if (B[top.second] < top.first) continue;
			for (const auto &[nxt, w] : graph[top.second]) {
				int ok = top.first + w;
				if (B[nxt] > ok) {
					B[nxt] = ok;
					pq.push({ok, nxt});
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (min(A[i][0], A[i][1]) > B[i]) ++ans;
	cout << ans;
}
