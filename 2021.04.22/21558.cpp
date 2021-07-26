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

	int n, sum = 0;
	cin >> n;
	vi vec(n);
	for (auto &i : vec) cin >> i, sum += i;

	vi Y;
	for (int i = 1; i <= sum; i++)
		if (sum % i == 0) Y.emplace_back(i);

	map<int, int> ans;

	for (const auto &y : Y) {
		int cnt = 0, where = 0;
		for (const auto &c : vec) {
			int t = c;
			if (where) {
				++cnt;
				int add = y - where;
				if (add <= t) {
					t -= add;
				} else {
					where += t;
					continue;
				}
			}
			where = t % y;
		}

		ans[cnt] = y;
	}

	int ok = 0;
	for (int i = 0; i < n; i++) {
		ok = max(ok, ans.count(i) ? ans[i] : 0);
		cout << ok << " ";
	}
}
