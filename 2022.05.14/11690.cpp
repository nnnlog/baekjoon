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

bitset<100000001> bit;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n; cin >> n;
	unsigned ans = 1;
	for (int i = 2; i <= n; i += 2) {
		if (bit[i]) continue;
		ll a = i;
		while (a * i <= n) a *= i;
		for (int j = i; j <= n; j += i) bit[j] = 1;
		ans *= a;
        if (i == 2) i--;
	}
	cout << ans;
}
