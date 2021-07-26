#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>

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

	int n, m; cin >> n >> m;
	vi ans(n + 1), lim(n + 1);
	unordered_map<int, vi> mp;
	while (m--) {
		int a, b; cin >> a >> b;
		mp[b].push_back(a);
	}
	ordered_set S;
	for (int i = 1; i <= n; i++) S.insert(i);
	for (int i = n; i >= 1; i--) {
		int current = *S.find_by_order(S.size() - mp[i].size() - 1);
		if (current < lim[i]) {
			cout << -1;
			return 0;
		}
		for (const auto &j : mp[i]) lim[j] = max(lim[j], current);
		S.erase(current);
		ans[i] = current;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
