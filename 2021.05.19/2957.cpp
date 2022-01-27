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
	vi mp(n * 4);
	ll ans = 0;
	int k = 0;
	set<pair<int, pii>> s;
	s.insert({mp[k] = 1e9, {1, 0}});
	while (n--) {
		int a;
		cin >> a;
		auto it = s.lower_bound({a, {0, 0}});
		int node = it->second.first;
		mp[node] = it->first;
		ans += it->second.second;
		s.insert({a - 1, {++k, it->second.second + 1}});
		s.insert({mp[node], {++k, it->second.second + 1}});
		s.erase(it);
		cout << ans << "\n";
	}
}
