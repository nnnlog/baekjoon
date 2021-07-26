#include <bits/stdc++.h>

using namespace std;

unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;

int solve(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return solve(20, 20, 20);
	if (dp[a][b][c]) return dp[a][b][c];
	if (a < b && b < c) return dp[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
	return dp[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
}

int a, b, c;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	cin >> a >> b >> c;
	while (a != -1 || b != -1 || c != -1) {
		cout << "w(" << a << ", " << b << ", " << c << ") = " << (dp[a][b][c] = solve(a, b, c)) << "\n";

		cin >> a >> b >> c;
	}
}