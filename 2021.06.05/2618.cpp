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

int dp[1001][1001];
pii track[1001][1001];

int dist(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, 0x3f3f3f3f, sizeof dp);
	int n, w;
	cin >> n >> w;
	vpii vec(w + 1);
	vi ans(w + 1);
	for (auto &[a, b] : vec | views::drop(1)) cin >> a >> b;

	auto A = [&](int k) {
		if (!k) return pii(1, 1);
		return vec[k];
	};
	auto B = [&](int k) {
		if (!k) return pii(n, n);
		return vec[k];
	};

	dp[0][0] = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			int k = max(i, j) + 1;
			if (dp[k][j] > dp[i][j] + dist(A(i), vec[k])) dp[k][j] = dp[i][j] + dist(A(i), vec[k]), track[k][j] = {i, j};
			if (dp[i][k] > dp[i][j] + dist(B(j), vec[k])) dp[i][k] = dp[i][j] + dist(B(j), vec[k]), track[i][k] = {i, j};
		}
	}
	int val = 1e9;
	int a, b;
	for (int i = 0; i <= w; i++) {
		if (val > dp[i][w]) val = dp[i][w], a = i, b = w;
		if (val > dp[w][i]) val = dp[w][i], a = w, b = i;
	}
	while (a || b) {
		pii prv = track[a][b];
		if (prv.first != a) ans[a] = 1;
		else ans[b] = 2;
		tie(a, b) = prv;
	}
	cout << val << "\n";
	for (auto i : ans | views::drop(1)) cout << i << "\n";
}
