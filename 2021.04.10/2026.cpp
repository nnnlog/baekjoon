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

int k, n, f;
vector<vi> G;

vi sel;
void solve(int b) {
	if (sel.size() == k) {
		for (auto &i : sel) cout << i << "\n";
		exit(0);
	}

	for (int i = b + 1; i <= n; i++) {
		int f = 0;
		for (const auto &j : sel) if (!G[i][j]) {
			f = 1;
			break;
		}
		if (f) continue;
		sel.emplace_back(i);
		solve(i);
		sel.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> k >> n >> f;
	G.assign(n + 1, vi(n + 1));
	while (f--) {
		int a, b; cin >> a >> b;
		G[a][b] = G[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		sel.emplace_back(i);
		solve(i);
		sel.pop_back();
	}

	cout << -1;
}
