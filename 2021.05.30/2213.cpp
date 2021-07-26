#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ld, ld> pld;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector <ld> vld;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef vector <pld> vpld;
typedef unordered_map<int, int> mpii;

int n;
vector <vi> graph, child;
vi weight;

void init(int curr, int prv) {
	for (int nxt : graph[curr]) if (nxt != prv) child[curr].push_back(nxt), init(nxt, curr);
}

int dp[10001][2];
vpii track[10001][2];

int solve_dp(int root, int f) {
	int &ret = dp[root][f];
	if (ret) return ret;
	if (f) {
		ret = weight[root];
		for (int nxt : child[root]) ret += solve_dp(nxt, 0), track[root][f].emplace_back(nxt, 0);
	} else
		for (int nxt : child[root]) {
			int a = solve_dp(nxt, 0), b = solve_dp(nxt, 1);
			track[root][f].emplace_back(nxt, a < b);
			ret += max(a, b);
		}
	return ret;
}

vi ans;

void solve_track(int node, int f) {
	if (f) ans.push_back(node);
	for (auto[a, b] : track[node][f]) solve_track(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	graph.resize(n + 1);
	child.resize(n + 1);
	weight.resize(n + 1);
	for (auto &i : weight | drop(1)) cin >> i;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	init(1, 1);
	cout << max(solve_dp(1, 0), solve_dp(1, 1)) << "\n";
	solve_track(1, solve_dp(1, 0) < solve_dp(1, 1));
	sort(all(ans));
	for (int i : ans) cout << i << " ";
}
