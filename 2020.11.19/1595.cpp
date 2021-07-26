#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef vector<int> vi;
typedef vector<ll> vl;

ull vis[10001];
vector<pull> graph[10001];

void dfs(ull a, ull c) {
	for (const auto &nxt : graph[a]) {
		if (vis[nxt.first]) continue;
		vis[nxt.first] = c + nxt.second;
		dfs(nxt.first, c + nxt.second);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<pair<ull, pull>> vec;

	string str;
	ull v = 0;
	while (getline(cin, str)) {
		if (str.empty() || str == "0") break;

		stringstream ss(str);
		ll a, b, c; ss >> a >> b >> c;
		v = a;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}


	ull mx = 0;
	for (ull i = 1; i <= 10000; i++) vis[i] = 0;
	vis[v] = 0;
	dfs(v, 0);
	for (ull i = 1; i <= 10000; i++) {
		if (mx < vis[i]) {
			mx = vis[i];
			v = i;
		}
	}

	for (ull i = 1; i <= 10000; i++) vis[i] = 0;
	vis[v] = 0;
	mx = 0;

	dfs(v, 0);
	for (ull i = 1; i <= 10000; i++) mx = max(mx, vis[i]);

	cout << mx;
}
