#include <bits/stdc++.h>

using namespace std;

int dp[2001];//[2001];
vector<int> book[11], sum[11];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		book[b].push_back(a);
	}

	for (auto &vec : book) sort(vec.begin(), vec.end(), greater<>());
	for (int i = 1; i <= 10; i++) {
		auto vec = book[i];

		sum[i].resize(vec.size());
		for (int j = 0; j < vec.size(); j++) {
			sum[i][j] = (j ? sum[i][j - 1] : 0) + vec[j];
		}

		//cout << i << ": ";
		//for (const auto &v : sum[i]) cout << v << " ";
		//cout << "\n";
	}

	int ans = 0;
	for (const auto &books : sum) {
		for (int base_cnt = k; base_cnt >= 0; base_cnt--) {
			for (int j = 1; j <= books.size(); j++) {
				if (base_cnt + j > k) break;
				if (!base_cnt || dp[base_cnt]) {
					dp[base_cnt + j] = max(dp[base_cnt + j], dp[base_cnt] + books[j - 1] + (j - 1) * j);
					//cout << base_cnt << " " << base_cnt + j << " " << dp[base_cnt + j] << "\n";
				}
			}
		}
		//cout << "\n";
	}

	cout << dp[k];
}
