#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

const int MX = 11;
int mp[MX][MX];
int dfs(int i, int vis) {
	if (i >= MX) return 0;
	int ret = 1e9;
	for (int j = 0; j < MX; j++) {
		if (vis & (1 << j) || !mp[i][j]) continue;
		int calc = dfs(i + 1, vis | (1 << j));
		
		if (calc != 1e9) {
			calc += mp[i][j];
			if (ret == 1e9) ret = calc;
			else ret = max(ret, calc);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		for (auto &i : mp)
			for (auto &j : i) cin >> j;

		cout << dfs(0, 0) << "\n";
	}
}
