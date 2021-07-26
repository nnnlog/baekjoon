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

ld intersect(pll a, pll b) {
	return ((ld) b.second - (ld) a.second) / ((ld) a.first - (ld) b.first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vl A(n + 1), B(n + 1), s(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] *= -1;
		A[i] = A[i - 1] + s[i];
		B[i] = B[i - 1] + A[i];
	}

	ll ans = min(0LL, s[1]);
	vector<pair<ld, pll>> vec = {{-1e18, {-1, 0}}};
	for (int i = 2; i <= n; i++) {
		pll fnc = {-i, B[i - 2]};
		ld cross = -1e18;
		while (!vec.empty()) {
			cross = intersect(fnc, vec.back().second);
			if (cross > vec.back().first) break;
			vec.pop_back();
		}
		vec.emplace_back(cross, fnc);

		auto it = --upper_bound(all(vec), pair<ld, pll>(A[i], {-1e9, -1e9}));
		ans = min(ans, s[i]);
		ans = min(ans, it->second.first * A[i] + it->second.second + A[i] * (i + 1) - B[i - 1]);
	}

	cout << -ans;
}
