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

	int n, l, k;
	cin >> n >> l >> k;
	vpii vec(n);
	for (auto &[a, b] : vec) cin >> b >> a;
	sort(all(vec));
	int ans = 0;
	while (k > 0 && k-- && !vec.empty())
		if (vec.begin()->first <= l) {
			vec.erase(vec.begin());
			ans += 140;
		} else {
			++k;
			break;
		}
	sort(all(vec), [](pii a, pii b) {
		return a.second < b.second;
	});
	while (k > 0 && k-- && !vec.empty())
		if (vec.begin()->second <= l) {
			vec.erase(vec.begin());
			ans += 100;
		} else break;
	cout << ans;
}
