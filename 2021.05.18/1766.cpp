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
	priority_queue<int, vi, greater<>> pq;
	vi vec(n + 1);
	vector<vi> graph(n + 1);
	while (m--) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		++vec[b];
	}
	for (int i = 1; i <= n; i++) if (!vec[i]) pq.push(i);
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		cout << top << " ";
		for (auto nxt : graph[top]) if (!--vec[nxt]) pq.push(nxt);
	}
}
