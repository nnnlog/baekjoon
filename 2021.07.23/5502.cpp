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

int dp[5000][5000];
int n;
string s;
int solve(int l, int r) {
	if (!l && r + 1 == n) return 0;
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	int a = 1e9, b = 1e9, c = 1e9;
	if (l && r + 1 < n && s[l - 1] == s[r + 1]) a = solve(l - 1, r + 1);
	if (l) b = solve(l - 1, r) + 1;
	if (r + 1 < n) c = solve(l, r + 1) + 1;
	return ret = min(a, min(b, c));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof dp);
	cin >> n;
	cin >> s;
	int ans = 1e9;
	for (int i = 1; i < n; i++) if (s[i - 1] == s[i]) ans = min(ans, solve(i - 1, i));
	for (int i = 0; i < n; i++) ans = min(ans, solve(i, i));
	cout << ans;
}
