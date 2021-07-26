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

#include <sys/stat.h>
#include <sys/mman.h>

signed I[36];
char *J = (char *) mmap(0, I[12], 1, 2, 0, fstat(0, (struct stat *) I));

int getu() {
	int x = 0;
	do x = x * 10 + *J - '0'; while (*++J >= '0');
	++J;
	return x;
}

int geti() {
	bool e = *J == '-';
	J += e;
	return (e ? -1 : 1) * getu();
}

int dp[500][500], mp[500][500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<pair<int, pii>> vec;
	int n, m;
	n = getu();
	m = getu();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			mp[i][j] = getu();
			if (mp[0][0] > mp[i][j]) vec.emplace_back(mp[i][j], pii(i, j));
		}

	dp[0][0] = 1;
	vec.emplace_back(mp[0][0], pii(0, 0));
	sort(all(vec), greater<>());
	for (const auto &[cnt, ij] : vec) {
		int i = ij.first, j = ij.second;
		if (i < n - 1 && mp[i + 1][j] < cnt) dp[i + 1][j] += dp[i][j];
		if (i && mp[i - 1][j] < cnt) dp[i - 1][j] += dp[i][j];
		if (j < m - 1 && mp[i][j + 1] < cnt) dp[i][j + 1] += dp[i][j];
		if (j && mp[i][j - 1] < cnt) dp[i][j - 1] += dp[i][j];
	}

	cout << dp[n - 1][m - 1];
}
