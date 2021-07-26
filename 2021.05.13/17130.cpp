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

enum DATA {
	EMPTY, CARROT, OUT, WALL
};
vector<vector<DATA>> arr;
vector<vi> dp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	dp.assign(n + 1, vi(m + 1, -1e9));
	arr.assign(n + 1, vector<DATA>(m + 1, EMPTY));
	pii curr;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == 'R') curr = {i, j}, dp[i][j] = 0;
			if (c == '#') arr[i][j] = WALL;
			if (c == 'C') arr[i][j] = CARROT;
			if (c == 'O') arr[i][j] = OUT;
		}
	int ans = -1;
	for (int j = curr.second; j <= m; j++)
		for (int i = j == curr.second ? curr.first : 1; i <= n; i++) {
			if (arr[i][j] == WALL) continue;
			if (arr[i][j] == OUT) ans = max(ans, dp[i][j]);
			if (j == m) continue;
			if (i > 1 && arr[i - 1][j + 1] != WALL) dp[i - 1][j + 1] = max(dp[i - 1][j + 1], dp[i][j] + (arr[i - 1][j + 1] == CARROT));
			if (arr[i][j + 1] != WALL) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + (arr[i][j + 1] == CARROT));
			if (i < n && arr[i + 1][j + 1] != WALL) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (arr[i + 1][j + 1] == CARROT));
		}
	cout << ans;
}
