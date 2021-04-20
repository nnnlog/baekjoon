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

string mp[10];

ll chk(ll a) {
	return (ll)sqrt(a) * (ll)sqrt(a) == a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	assert(n), assert(m);
	for (int i = 1; i <= n; i++) cin >> mp[i], mp[i].insert(mp[i].begin(), '-');

	ll ans = -1;
	for (int a = 1; a <= n; a++)
		for (int b = 1; b <= m; b++)
			for (int dx = -n; dx <= n; dx++)
				for (int dy = -m; dy <= m; dy++) {
					if (!dx && !dy) continue;
					string str;
					for (int x = 0; a + dx * x >= 1 && a + dx * x <= n && b + dy * x >= 1 && b + dy * x <= m; x++) {
						str.push_back(mp[a + dx * x][b + dy * x]);
						ll t = atoll(str.c_str());
						if (chk(t)) ans = max(ans, t);
					}
				}
	cout << ans;
}
