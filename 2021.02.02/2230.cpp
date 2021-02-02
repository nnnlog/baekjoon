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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	vl vec(n);
	for (auto &i : vec) cin >> i;
	sort(all(vec));
	ll ans = 1e18;
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(all(vec), m + vec[i]);
		if (it != vec.end()) ans = min(ans, *it - vec[i]);
	}
	cout << ans;
}
