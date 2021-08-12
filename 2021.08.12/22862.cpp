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

	int n, k; cin >> n >> k;
	vi vec(n);
	for (auto &i : vec) cin >> i;
	int l = 0, r = 0;
	vi cnt(2);
	cnt[vec[0] % 2]++;
	int ans = cnt[0];
	while (l < n) {
		if (r + 1 < n && (vec[r + 1] % 2) + cnt[1] <= k) ++cnt[vec[++r] % 2];
		else --cnt[vec[l++] % 2];
		ans = max(ans, cnt[0]);
	}
	cout << ans;
}
