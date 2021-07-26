#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace __gnu_pbds;

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
	while (T--) {
		int n; cin >> n;
		map<int, vi> mp;
		while (n--) {
			int a, b; cin >> a >> b;
			mp[a].emplace_back(b);
		}
		ll ans = 0;
		tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> Y;
		for (auto &[x, vec] : mp) {
			sort(all(vec), greater<>());
			for (auto &y : vec) {
				ans += Y.size() - Y.order_of_key(y);
				Y.insert(y);
			}
		}
		cout << ans << "\n";
	}
}
