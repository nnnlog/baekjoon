#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

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

	int r, c;
	cin >> r >> c;
	vector<vpii> sum(r + 1, vpii(c + 1));
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			string s;
			cin >> s;
			int cnt = atoi(s.substr(1).c_str());
			if (s[0] == 'A') sum[i][j].first += cnt;
			else sum[i][j].second += cnt;
			sum[i][j].first += sum[i - 1][j].first + sum[i][j - 1].first - sum[i - 1][j - 1].first;
			sum[i][j].second += sum[i - 1][j].second + sum[i][j - 1].second - sum[i - 1][j - 1].second;
		}
	auto l_sum = [&](int a, int b, int c, int d) {
		if (b > d) return 0;
		return sum[c][d].first - sum[a - 1][d].first - sum[c][b - 1].first + sum[a - 1][b - 1].first;
	};
	auto r_sum = [&](int a, int b, int c, int d) {
		if (b > d) return 0;
		return sum[c][d].second - sum[a - 1][d].second - sum[c][b - 1].second + sum[a - 1][b - 1].second;
	};
	vector<vi> dp(r + 1, vi(c + 1));
	dp[1][1] = r_sum(1, 2, 1, c);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			if (j < c) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - r_sum(i, j + 1, i, j + 1));
			if (i < r) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + l_sum(i + 1, 1, i + 1, j - 1) + r_sum(i + 1, j + 1, i + 1, c));
			if (i < r && j < c) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + l_sum(i + 1, 1, i + 1, j) + r_sum(i + 1, j + 2, i + 1, c));
		}
	cout << dp.back().back();
}
