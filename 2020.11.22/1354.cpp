#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

unordered_map<ll, ull> mp;
ll n, p, q, x, y;

ull solve(ll i) {
	if (i <= 0) return 1;
	if (mp[i]) return mp[i];
	return mp[i] = solve(i / p - x) + solve(i / q - y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> p >> q >> x >> y;

	cout << solve(n);
}
