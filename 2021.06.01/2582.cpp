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

	int n; cin >> n;
	vi vec(n);
	ld E1 = 0, T = 1, k = 1, ans = 0;
	for (auto &i : vec) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			i |= (c == 'H') << j;
			E1 += c == 'H';
		}
	}
	ans = E1;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, n - 1);
	auto rand = bind(distribution, generator);

	int state = 0;
	for (int i = 0; i < 100000; i++) {
		int nxt = state ^ (1 << rand());
		ld E2 = 0;
		for (auto j : vec) {
			int t = __builtin_popcount(j ^ nxt);
			E2 += min(t, n - t);
		}
		ld p = exp((E1 - E2) / k * T);
		if (p > ld(rand()) / (n - 1)) {
			E1 = E2;
			state = nxt;
		}
		ans = min(ans, E2);
		T *= 0.9999;
	}
	cout << ans;
}
