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

	ll n, m; cin >> n >> m;
	vl vec(n);
	for (auto &i : vec) cin >> i;
	ll l = 0, r = 1e9;
	while (l < r) {
		ll mid = (l + r) >> 1, cnt = 0;
		for (const auto &i : vec) cnt += max(0LL, i - mid);
		if (cnt < m) r = mid;
		else if (l == mid) break;
		else l = mid;
	}
	cout << (l + r >> 1);
}
