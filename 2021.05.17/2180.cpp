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

	int n;
	cin >> n;
	vpii vec(n);
	for (auto &[a, b] : vec) cin >> a >> b;
	sort(all(vec), [](pii &a, pii &b) {
		if (!a.first) return false;
		else if (!b.first) return true;
		else if (!a.second && !b.second) return a.first < b.first;
		return (ld)a.second / a.first < (ld)b.second / b.first;
	});
	ll ans = 0;
	for (const auto &[a, b] : vec) ans += a * ans + b, ans %= 40000;
	cout << ans;
}
