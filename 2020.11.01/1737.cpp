#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull MOD = 1000000000000000000;

ull dp[1001][1001];
long double n;

ull solve(int i, int j) {
	long double curr = n - 1 * i - M_PI * (long double)j;
	if (0 <= curr && curr <= M_PI) return 1;
	else if (curr < 0) return 0;
	
	if (dp[i][j]) return dp[i][j];
	
	return dp[i][j] = (solve(i + 1, j) + solve(i, j + 1)) % MOD;
}

int main() {
	cin >> n;
	cout << solve(0, 0);
}
