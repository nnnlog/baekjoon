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

	ll n, k, l = 1, r = 1e18; cin >> n >> k;
	while (l < r) {
		ll mid = (l + r) >> 1, cnt = 0;
		for (int i = 1; i <= n; i++) cnt += min(n, mid / i);
		//cout << mid << " " << cnt << "\n";
		if (cnt >= k) r = mid;
		else l = mid + 1;
	}
	cout << ((l + r) >> 1);
}
