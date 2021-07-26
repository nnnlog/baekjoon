#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

ull dp[1000001];
ull MOD = 1e9;

ull solve(int n) {
	if (n < 0) return 0;
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (n == 3) return 2;
	if (n == 4) return 9;

	ull &ret = dp[n];
	if (ret) return ret;
	return ret = ((solve(n - 1) + solve(n - 2)) * (n - 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	cout << solve(n);
}
