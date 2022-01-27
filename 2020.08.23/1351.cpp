#include <bits/stdc++.h>

using namespace std;
long long n, p, q;

unordered_map<long long, long long> dp;

long long solve(long long i) {
	if (!i) return 1;
	if (dp[i]) return dp[i];
	return dp[i] = solve(i / p) + solve(i / q);
}

int main() {
	cin >> n >> p >> q;
	cout << solve(n);
}
