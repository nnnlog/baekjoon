#include <bits/stdc++.h>

using namespace std;

int dp[2][1001][1001], card[1001];

int solve(int turn, int l, int r) {
	if (l >= r) {
		if (!turn) return card[l];
		else return 0;
	}

	int &ret = dp[turn][l][r];
	if (ret) return ret;

	if (!turn) return ret = max(solve(!turn, l + 1, r) + card[l], solve(!turn, l, r - 1) + card[r]);
	else return ret = min(solve(!turn, l + 1, r), solve(!turn, l, r - 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 1001; j++)
				for (int k = 0; k < 1001; k++)
					dp[i][j][k] = 0;

		for (int i = 1; i <= n; i++) cin >> card[i];
		cout << solve(0, 1, n) << "\n";
	}
}
