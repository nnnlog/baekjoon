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

	int T; cin >> T;
	mpii proc;
	vi vec(T);
	for (auto &i : vec) cin >> i, ++proc[i];
	reverse(all(vec));
	map<int, pii> ans;
	for (auto [a, b] : proc) ans[a].first = b;
	int prv = -1e9, nxt = 0;
	for (const auto &i : vec) {
		if (i >= prv) ans[i].second = ++nxt;
		else ans[i].second = nxt;
		prv = i;
	}
	cout << ans.size() << "\n";
	for (auto [a, bc] : ans) cout << a << " " << bc.first << " " << bc.second << "\n";
}
