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

	int n, m; cin >> n >> m;
	vector<pair<string, string>> vec(n);
	auto name = [&](string s) {
		int p = s.find_last_of(".");
		return s.substr(0, p);
	};
	auto ext = [&](string s) {
		int p = s.find_last_of(".") + 1;
		return s.substr(p);
	};
	for (auto &[x, y] : vec) {
		string a; cin >> a;
		x = name(a);
		y = ext(a);
	}
	map<string, int> mp;
	while (m--) {
		string s; cin >> s;
		mp[s] = 1;
	}
	auto dict = [&](string a, string b) {
		for (int i = 0; i < min(a.size(), b.size()); i++) {
			if (a[i] != b[i]) return int(a[i] < b[i]);
		}
		if (a.size() != b.size()) return int(a.size() < b.size());
		return -1;
	};
	sort(all(vec), [&](auto a, auto b) {
		int cmp = dict(a.first, b.first);
		if (cmp > -1) return cmp;
		if (mp.count(a.second) ^ mp.count(b.second)) return int(mp.count(a.second));
		return dict(a.second, b.second);
	});
	for (auto [a, b] : vec) cout << a << "." << b << "\n";
}
