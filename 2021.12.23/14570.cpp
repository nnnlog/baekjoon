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

vpii child;
int dfs(int u, ll k) {
	if (child[u].first == child[u].second) return u;
	if (child[u].first == -1) return dfs(child[u].second, k);
	if (child[u].second == -1) return dfs(child[u].first, k);
	if (k % 2) return dfs(child[u].first, k / 2 + 1);
	else return dfs(child[u].second, k / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	child.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		child[i] = {a, b};
	}
	ll k; cin >> k;
	cout << dfs(1, k);
}
