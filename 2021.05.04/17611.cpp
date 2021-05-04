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
	pii first, last;
	vpii X, Y;
	for (int i = 0; i <= n; i++) {
		int a, b;
		if (i < n) cin >> a >> b;
		else a = first.first, b = first.second;
		if (!i) first = {a, b};
		else {
			if (last.first == a) {
				int x = last.second, y = b;
				if (x > y) swap(x, y);
				Y.emplace_back(x, 1);
				Y.emplace_back(y, -1);
			} else {
				int x = last.first, y = a;
				if (x > y) swap(x, y);
				X.emplace_back(x, 1);
				X.emplace_back(y, -1);
			}
		}
		last = {a, b};
	}
	sort(all(X));
	sort(all(Y));
	auto solve = [](auto &vec) {
		int ret = 0, sum = 0, adding = 0;
		for (const auto &[a, b] : vec) {
			if (adding && b == -1) {
				ret = max(ret, sum);
				adding = 0;
			}
			if (b == 1) adding = 1;
			sum += b;
		}
		return ret;
	};
	cout << max(solve(X), solve(Y));
}
