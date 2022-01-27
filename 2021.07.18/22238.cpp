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

	auto gen = [&](int a, int b) {
		if (a && b) {
			int g = gcd(a, b);
			a /= g, b /= g;
			return pii(a, b);
		} else if (!a) return pii(0, b > 0 ? 1 : -1);
		else return pii(a > 0 ? 1 : -1, 0);
	};

	int n, m; cin >> n >> m;
	map<int, map<int, vi>> mp;
	map<int, map<int, ll>> atk;
	int living = n;
	while (n--) {
		int a, b, w; cin >> a >> b >> w;
		pii x = gen(a, b);
		mp[x.first][x.second].push_back(w);
	}
	for (auto &[k, a] : mp) for (auto &[kk, vec] : a) sort(all(vec));
	while (m--) {
		int a, b, w; cin >> a >> b >> w;
		pii x = gen(a, b);
		ll org = atk[x.first][x.second];
		int dead = upper_bound(all(mp[x.first][x.second]), atk[x.first][x.second] += w) - upper_bound(all(mp[x.first][x.second]), org);
		living -= dead;
		cout << living << "\n";
	}
}
