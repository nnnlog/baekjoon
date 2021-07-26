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
typedef pair<ld, ld> pld;

ld intersect(pld a, pld b) {
	return (b.second - a.second) / (a.first - b.first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vl a(n), b(n), dp(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;

	vector<pair<ld, pld>> s;
	for (int i = 1; i < n; i++) {
		pld linear = {b[i - 1], dp[i - 1]};
		ld x = 0;
		while (!s.empty()) {
			x = intersect(s.back().second, linear);
			if (s.back().first < x) break;
			s.pop_back();
		}

		s.emplace_back(x, linear);

		auto it = upper_bound(all(s), pair<ld, pld>(a[i], pld(-1, -1)));
		--it;
		dp[i] = it->second.first * a[i] + it->second.second;
	}

	cout << dp[n - 1];
}
