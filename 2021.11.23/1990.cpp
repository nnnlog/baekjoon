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

bool is_prime(ll a) {
	for (ll i = 2; i * i <= a; i++) {
		if (a % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b; cin >> a >> b;

	vl ans;
	for (int i = 1; i <= 10000; i++) {
		string s = to_string(i);
		string t = s;
		reverse(all(t));

		s += t;
		ll x = atoll(s.c_str());
		if (a <= x && x <= b && is_prime(x)) ans.push_back(x);

		s.erase(t.size(), 1);
		x = atoll(s.c_str());
		if (a <= x && x <= b && is_prime(x)) ans.push_back(x);
	}
	sort(all(ans));
	ans.push_back(-1);

	for (ll i : ans) cout << i << "\n";
}
