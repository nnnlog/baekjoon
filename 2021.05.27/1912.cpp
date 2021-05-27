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
	vi vec(n), dp(n);
	for (auto &i : vec) cin >> i;
	if (*max_element(all(vec)) <= 0) {
		cout << *max_element(all(vec));
		return 0;
	}
	for (int i = 0; i < n; i++) {
		dp[i] = max(dp[i - 1] + vec[i], 0);
	}
	cout << *max_element(all(dp));
}
