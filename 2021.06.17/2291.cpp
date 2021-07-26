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

int dp[221][11][221];

int cnt(int first, int len, int sum) {
	if (len == 1) return first <= sum;
	int &ret = dp[first][len][sum];
	if (ret == -1) {
		ret = 0;
		for (int i = first; i <= sum; i++) ret += cnt(i, len - 1, sum - i);
	}
	return ret;
}

vi ans;

void solve(int first, int len, int sum, int k) {
	if (len == 1) {
		ans.push_back(sum);
		return;
	}
	int A = cnt(first, len - 1, sum - first);
	if (A >= k) {
		ans.push_back(first);
		solve(first, len - 1, sum - first, k);
	} else solve(first + 1, len, sum, k - A);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	int n, m, k;
	cin >> n >> m >> k;
	solve(1, n, m, k);
	for (int i : ans) cout << i << " ";
}
