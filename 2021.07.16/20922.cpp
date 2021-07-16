#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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

	int n, k;
	cin >> n >> k;
	vi vec(n + 1);
	for (auto &i : vec | drop(1)) cin >> i;
	vector<mpii> cnt(k + 2);
	int l = 1, r = 1, ans = 1;
	cnt[1][vec[1]] = 1;
	auto gt = [&](int j) {
		for (int i = 1; i <= k + 1; i++)
			if (cnt[i].count(j)) return i;
		return 0;
	};
	while (l < n && r <= n) {
		int f = cnt.back().empty();
		if (f) ans = max(ans, r - l + 1);
		if (!f || r == n) {
			int a = vec[l++];
			int c = gt(a);
			cnt[c].erase(a);
			if (c > 1) cnt[c - 1][a] = 1;
		} else {
			int a = vec[++r];
			int c = gt(a);
			cnt[c].erase(a);
			cnt[c + 1][a] = 1;
		}
	}
	cout << ans;
}
