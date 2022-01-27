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

	int n; cin >> n;
	vi vec(n);
	set<int> s;
	for (int i = 1; i <= 2 * n; i++) s.insert(i);
	for (auto &i : vec) cin >> i, s.erase(i);
	int ans = 0;
	for (const auto &i : vec) {
		auto it = s.lower_bound(i);
		if (it != s.end()) {
			ans++;
			s.erase(it);
		}
	}
	cout << ans;
}
