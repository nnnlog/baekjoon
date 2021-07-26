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

ll _pow(ll base, ll exp) {
	if (exp == 0) return 1;
	ll ret = _pow((base * base) % 1000000007, exp / 2);
	if (exp % 2) ret *= base;
	return ret % 1000000007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll a, b, n; cin >> a >> b >> n;
	cout << _pow((1LL << 31), n - 1);
}
