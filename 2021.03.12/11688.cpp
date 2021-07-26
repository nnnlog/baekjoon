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

vi prime;
int vis[1000001];

map<ll, ll> fact(ll a) {
	map<ll, ll> mp;
	for (const auto &p : prime) {
		while (a % p == 0) a /= p, mp[p]++;
	}
	if (a > 1) mp[a]++;
	return mp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 2; i <= 1000000; i++) {
		if (vis[i]) continue;
		prime.push_back(i);
		for (int j = i; j <= 1000000; j += i) vis[j] = 1;
	}

	ll a, b, L; cin >> a >> b >> L;
	ll l = a * b / gcd(a, b);
	auto A = fact(l), B = fact(L);
	ll ans = 1;
	for (const auto &[a, b] : A) {
		if (B[a] < b) {
			cout << -1;
			return 0;
		}
	}

	for (const auto &[a, b] : B) {
		if (A[a] != b) ans *= powl(a, b);
	}

	cout << ans;
}
