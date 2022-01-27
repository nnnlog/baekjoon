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

int vis[5001][5001];

int n;
vi vec;

void solve(int l, int r) {
	if (vis[l][r]) return;
	vis[l][r] = 1;
	if (l && r < n && vec[l - 1] == vec[r + 1]) solve(l - 1, r + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	 cin >> n;
	 vec.resize(n + 1);
	 for (auto &i : vec | views::drop(1)) cin >> i;

/*n = 5000;
vec.assign(n + 1, 1);*/
	 for (int i = 1; i < n; i++) if (vec[i] == vec[i + 1]) solve(i, i + 1);
	 vi dp(n + 1, -1);
	 dp[0] = 0;
	 for (int r = 1; r <= n; r++) {
	 	for (int l = 1; l < r; l++) {
	 		if ((r - l) % 2 && vis[l][r] && dp[l - 1] >= 0) {
	 			dp[r] = max(dp[r], dp[l - 1] + 1);
	 		}
	 	}
	 }
	 cout << dp.back();
}
