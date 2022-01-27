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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vi vec(n);
	for (auto &i : vec) cin >> i;
	vi dp(50001);
	for (const auto &i : vec) {
		vi tmp = dp;
		for (int j = 15000; j >= 1; j--) {
			if (!dp[j]) continue;
			int a = i, b = j;
			if (a > b) swap(a, b);
			tmp[a + b] = 1;
			tmp[b - a] = 1;
		}
		tmp.swap(dp);
		dp[i] = 1;
	}
	int q; cin >> q;
	while (q--) {
		int a; cin >> a;
		cout << (dp[a] ? "Y" : "N") << " ";
	}
}
