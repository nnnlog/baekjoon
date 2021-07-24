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

struct Hashing {
	ll p, mod;
	vl prefix, base;

	ll init(string &s) {
		prefix.resize(s.size() + 1);
		base.resize(s.size() + 1);
		base[0] = 1;
		for (int i = 1; i <= s.size(); i++) {
			prefix[i] = (prefix[i - 1] * p + s[i - 1]) % mod;
			base[i] = (base[i - 1] * p) % mod;
		}
		return prefix.back();
	}

	ll substr(int l, int r) {
		ll ret = (prefix[r] - prefix[l - 1] * base[r - l + 1]) % mod;
		if (ret < 0) ret += mod;
		return ret;
	}
};

Hashing H1{1226, ll(1e9 + 7)}, H2{1226, ll(1e9 + 9)};

pll substr(int l, int r) {
	return {H1.substr(l, r), H2.substr(l, r)};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string T, P;
	getline(cin, T);
	getline(cin, P);

	pll cmp = {H1.init(P), H2.init(P)};
	//cout << cmp.first << " " << cmp.second << "\n";
	//cout << H1.init(T.substr(15, P.size())) << " " << cmp.second << "\n";
	H1.init(T), H2.init(T);
	vi ans;
	for (int i = 1; i + P.size() - 1 <= T.size(); i++) {
		//cout << i << " " << substr(i, i + P.size()).first << " " << substr(i, i + P.size()).second << "\n";
		if (substr(i, i + P.size() - 1) == cmp) ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for (int i : ans) cout << i << " ";
}
