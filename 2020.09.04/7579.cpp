#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> mem;
vector<int> dp;
int n, m;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	mem.resize(n);
	int sum = 0;

	for (int i = 0; i < n; i++) cin >> mem[i].first;
	for (int i = 0; i < n; i++) {
		cin >> mem[i].second;
		sum += mem[i].second;
	}
	dp.resize(sum + 1);
	//dp[mem[0].second] = mem[0].first;
	int ans = 1e9;
	for (int i = 0; i < n; i++)
		for (int cost = sum; cost >= mem[i].second; cost--) {
			dp[cost] = max(dp[cost], dp[cost - mem[i].second] + mem[i].first);
			if (dp[cost] >= m) ans = min(ans, cost);
		}


	cout << ans;
}
