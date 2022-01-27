#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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
	vi vec(n + 1), sum(n + 1);
	for (auto &i : vec | drop(1)) cin >> i;
	sort(all(vec));
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + vec[i];
	int a, b; cin >> a >> b;
	vi dp(n + 1, 1e9);
	dp[0] = 0;
	for (int r = 1; r <= n; r++) {
		for (int l = 1; l <= r; l++) {
			int mid = (l + r) >> 1;
			int cost = min((sum[r] - sum[l - 1]) * a, b + a * ((mid - l + 1) * vec[mid] - (sum[mid] - sum[l - 1]) + sum[r] - sum[mid - 1] - (r - mid + 1) * vec[mid]));
			dp[r] = min(dp[r], dp[l - 1] + cost);
		}
	}
	cout << dp.back();
}
