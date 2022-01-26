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

int n;
queue<int> Q;
vector<vi> ans;

void dfs(int depth) {
	if ((1 << depth) < n) dfs(depth + 1);
	ans[depth - 1].push_back(Q.front()), Q.pop();
	if ((1 << depth) < n) dfs(depth + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	ans.resize(n);
	n = 1 << n;
	for (int i = 1; i < n; i++) {
		int a; cin >> a;
		Q.push(a);
	}

	dfs(1);

	for (const auto &v : ans) {
		for (int i : v) cout << i << " ";
		cout << "\n";
	}
}
