#include <iostream>
#include <cmath>

using namespace std;

int sum[50001], dp[3][50001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	cin >> m;
	for (int i = 0; i < 3; i++)
		for (int j = i * m; j <= n; j++)
			dp[i][j] = max(dp[i][j - 1], (i ? dp[i - 1][j - m] : 0) + sum[j] - sum[j - m]);

	cout << dp[2][n];
}
