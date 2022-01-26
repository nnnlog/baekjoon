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

	int n; cin >> n;
	map<ll, ll> mp;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		mp[a] += b;
		sum += b;
	}
	vl ans;
	ll curr = 0;
	for (const auto &[a, b] : mp) {
		ll prv = curr;
		curr += b;
		if (prv - 1 <= sum / 2 && sum / 2 <= curr + 1) ans.push_back(a);
	}

	pair<__int128, ll> ok = {numeric_limits<__int128>::max(), 0};
	for (ll p : ans) {
		__int128 s = 0;
		for (const auto &[a, b] : mp) s += __int128(abs(a - p)) * b;
		ok = min(ok, {s, p});
	}
	cout << ok.second;
}
