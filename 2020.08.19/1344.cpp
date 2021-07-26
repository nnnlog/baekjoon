#include <bits/stdc++.h>

using namespace std;

long double dp[19][19][19];

bool isPrime(int n) {
	switch (n) {
		case 2:
		case 3:
		case 5:
		case 7:
		case 11:
		case 13:
		case 17:
			return true;
		default:
			return false;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	long double a, b;
	cin >> a >> b;
	dp[0][0][0] = 1.0;

	a /= 100.0;
	b /= 100.0;
	for (int t = 1; t <= 18; t++)
		for (int i = 0; i <= t; i++)
			for (int j = 0; j <= t; j++) {
				if (i > 0) dp[t][i][j] += dp[t - 1][i - 1][j] * a * (1.0 - b);
				if (j > 0) dp[t][i][j] += dp[t - 1][i][j - 1] * (1.0 - a) * b;
				if (i > 0 && j > 0) dp[t][i][j] += dp[t - 1][i - 1][j - 1] * a * b;
				dp[t][i][j] += dp[t - 1][i][j] * (1.0 - a) * (1.0 - b);
			}

	long double ans = 0;
	for (int i = 0; i <= 18; i++)
		for (int j = 0; j <= 18; j++)
			if (isPrime(i) || isPrime(j)) ans += dp[18][i][j];

	cout.precision(15);
	cout << fixed << ans;
}
