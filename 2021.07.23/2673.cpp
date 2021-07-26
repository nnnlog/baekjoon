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

int mp[100][100], dp[100][100], n;
int solve(int l, int r) {
	if (l == r) return 0;
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = l; i < r; i++) {
		ret = max(ret, solve(l, i) + solve(i + 1, r) + mp[l][r]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof dp);

	cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		mp[--a][--b] = 1;
	}
	cout << solve(0, 99);
}
