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


vi vis;
vi ans;
int b;
int dfs(int node, int n, int f = 0) {
	if (node > n) return 0;
	if (f) {
		if (b <= n) vis[b] = node, ans[node] = b++;
		else {
			cout << -1;
			exit(0);
		}
	}
	return 1 + dfs(node * 2, n, f) + dfs(node * 2 + 1, n, f);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, p; cin >> n >> k >> p;
	vis.resize(n + 1);
	ans.resize(n + 1);
	int a = p, i = 1;
	vi back;
	while (a /= 2) back.push_back(a);
	reverse(all(back));
	for (const auto &j : back) vis[i] = j, ans[j] = i++;
	if (i > k) {
		cout << -1;
		return 0;
	}
	b = k;
	dfs(p, n, 1);
	int nxt = 1;
	for (int j = 1; j <= n; j++) if (!ans[j]) {
		while (nxt <= n && vis[nxt]) ++nxt;
		if (vis[nxt]) {
			cout << -1;
			return 0;
		}
		vis[nxt] = j;
		ans[j] = nxt;
	}
	for (int j = 1; j <= n; j++) cout << ans[j] << "\n";
}
