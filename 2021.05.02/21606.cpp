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

vector<vi> graph;
vi vec, vis, par;

void make(int a) {
	for (const auto &nxt : graph[a]) {
		if (!vis[nxt]) {
			vis[nxt] = 1;
			par[nxt] = a;
			make(nxt);
		}
	}
}

void solve(int a, int prv, bool first = 0) {
	if ((!first && vec[a])) {
		++vis[prv];
		return;
	}
	if (!a) {
		++vis[a];
		return;
	}
	solve(par[a], a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vec.resize(n + 1);
	graph.resize(n + 1);
	par.resize(n + 1);
	vis.resize(n + 1);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) vec[i + 1] = s[i] - '0';
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vis[1] = 1;
	make(1);
	vis.assign(n + 1, 1);
	vis[0] = 0;
	//for (int i = 0; i <= n; i++) if (vec[i]) vis[i] = 0;
	for (int i = 1; i <= n; i++) if (vec[i]) solve(i, 0, 1);
	ll ans = 0;
	for (const auto &i : vis) ans += i * (i - 1);
	cout << ans;
}
