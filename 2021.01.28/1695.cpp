#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int dp[5001][5001];
vi vec;

int solve(int a, int b) {
	if (a >= b) return 0;
	int &ret = dp[a][b];
	if (ret) return ret;
	ret = 1e9;
	if (vec[a] == vec[b]) ret = solve(a + 1, b - 1);
	else ret = min(solve(a + 1, b), solve(a, b - 1)) + 1;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vec.resize(n);
	for (auto &i : vec) cin >> i;

	cout << solve(0, n - 1);
}
