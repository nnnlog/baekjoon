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

	int q; cin >> q;
	unordered_map<string, priority_queue<int>> mp;
	ll ans = 0;
	while (q--) {
		int k; cin >> k;
		string s; cin >> s;
		int f; cin >> f;
		if (k == 1) {
			while (f--) {
				int a; cin >> a;
				mp[s].push(a);
			}
		} else {
			while (!mp[s].empty() && f--) {
				int t = mp[s].top(); mp[s].pop();
				ans += t;
			}
		}
	}
	cout << ans;
}
