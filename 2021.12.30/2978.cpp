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

	string str; cin >> str;
	string a = str.substr(0, str.find('='));
	int s = atoi(str.substr(str.find('=') + 1).c_str());

	int n = a.size();
	a.insert(a.begin(), '0');

	vector<map<int, vi>> table(n + 1);
	for (int l = 1; l <= n; l++) {
		int sum = 0;
		for (int r = l; r <= n; r++) {
			sum *= 10;
			sum += a[r] - '0';
			if (sum > s) break;
			if (!table[r].count(sum)) table[r][sum] = {l};
			else if (sum > 0) table[r][sum].push_back(l);
		}
	}

	vector<vi> dp(n + 1, vi(5001, 1e9));
	vector<vpii> track(n + 1, vpii(5001));
	dp[0][0] = 0;
	for (int r = 1; r <= n; r++) {
		for (int j = 1; j <= s; j++) {
			for (const auto &[sum, vec] : table[r]) {
				if (j < sum) break;
				for (int l : vec) {
					if (dp[r][j] > dp[l - 1][j - sum] + 1) {
						dp[r][j] = dp[l - 1][j - sum] + 1;
						track[r][j] = {l - 1, j - sum};
					}
				}
			}
		}
	}

	assert(dp[n][s] < 1e9);
	vi ans(n + 1);
	for (pii i = {n, s}; i.first && i.second; i = track[i.first][i.second]) ans[i.first] = 1;
	for (int i = 1; i <= n; i++) {
		cout << a[i];
		if (i < n && ans[i]) cout << '+';
	}
	cout << '=' << s;
}
