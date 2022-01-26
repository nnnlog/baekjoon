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

int dp[1 << 17][26];
vector<string> vec;

int solve(int a, int b) {
	int &ret = dp[a][b - 'A'];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (!(a & (1 << i)) && b == vec[i].front()) {
			ret = max(ret, solve(a | (1 << i), vec[i].back()) + int(vec[i].size()));
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (auto &v : dp)
		for (auto &i : v) i = -1;

	int n; cin >> n;
	vec.resize(n);
	for (auto &i : vec) cin >> i;

	int ans = 0;
	for (int i = 0; i < vec.size(); i++) ans = max(ans, solve(1 << i, vec[i].back()) + int(vec[i].size()));

	cout << ans;
}
