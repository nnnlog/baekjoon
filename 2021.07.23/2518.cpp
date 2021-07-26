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

ll dp[101][101][101][3];
int n;

int dist(int i, int j) {
	if (i > j) swap(i, j);
	return min(j - i, i + n - j);
}

vi vec[3];

ll solve(int i, int j, int k, int f) {
	if (i + 1 == vec[0].size() && j + 1 == vec[1].size() && k + 1 == vec[2].size()) return 0;
	ll &ret = dp[i][j][k][f];
	if (ret != -1) return ret;
	ret = 1e18;
	int curr = 0;
	if (f == 0) curr = vec[0][i];
	if (f == 1) curr = vec[1][j];
	if (f == 2) curr = vec[2][k];
	if (i + 1 < vec[0].size()) ret = min(ret, solve(i + 1, j, k, 0) + dist(curr, vec[0][i + 1]));
	if (j + 1 < vec[1].size()) ret = min(ret, solve(i, j + 1, k, 1) + dist(curr, vec[1][j + 1]));
	if (k + 1 < vec[2].size()) ret = min(ret, solve(i, j, k + 1, 2) + dist(curr, vec[2][k + 1]));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 0; i < 3; i++) {
		int k;
		cin >> k;
		int add = 0;
		if (i == 1) add = 2 * n / 3;
		if (i == 2) add = n / 3;
		vec[i].push_back(0);
		while (k--) {
			int a;
			cin >> a;
			vec[i].push_back((a - 1 + add) % n);
		}
	}

	cout << solve(0, 0, 0, 3);
}
