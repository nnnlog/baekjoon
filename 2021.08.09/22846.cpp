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

int k;
vector<vi> dp(1e5 + 1, vi(2, -1));
int solve(int n, int f) {
	if (n == k) return !f;
	int &ret = dp[n][f];
	if (ret != -1) return ret;
	ret = !f;
	for (int i = 1; i * i <= n; i++) {
		if (n % i) continue;
		if (n + i <= k && f == solve(n + i, !f)) return ret = f;
		if (n + n / i <= k && f == solve(n + n / i, !f)) return ret = f;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> k;
	//int k = atoi(argv[1]);
	cout << (solve(1, 0) ? "Ringo" : "Kali");
	//cout << (solve(k, 1) ? "Kali" : "Ringo");
}
