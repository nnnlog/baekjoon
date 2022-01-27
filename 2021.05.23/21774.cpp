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

typedef __int128 i128;

pll parse(string ymd, string hms_lvl) {
	return {atoll((ymd.substr(0, 4) + ymd.substr(5, 2) + ymd.substr(8, 2) + hms_lvl.substr(0, 2) + hms_lvl.substr(3, 2) +
	              hms_lvl.substr(6, 2)).c_str()), (hms_lvl.back() - '0')};
}

vector<vl> lvl(7);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q; cin >> n >> q;
	while (n--) {
		string a, b; cin >> a >> b;
		auto ret = parse(a, b);
		lvl[ret.second].push_back(ret.first);
	}
	for (auto &v : lvl) sort(all(v));
	while (q--) {
		string a, b, c; cin >> a >> b >> c;
		string f, e;
		f = b.substr(0, b.find('#'));
		e = b.substr(b.find('#') + 1);

		auto S = parse(a, f);
		auto E = parse(e, c);

		ll ans = 0;
		for (int i = E.second; i <= 6; i++) ans += upper_bound(all(lvl[i]), E.first) - lower_bound(all(lvl[i]), S.first);
		cout << ans << "\n";
	}
}
