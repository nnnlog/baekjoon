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

ll n;
ll diff = 1e18, ans = 1e18;
vi vec(10);

void solve(ll i) {
	ll curr = abs(n - i);
	if (curr < diff) {
		diff = curr;
		ans = i;
	} else if (curr == diff) ans = min(ans, i);

	for (ll j = 0; j < 10; j++) {
		if (!vec[j]) {
			vec[j] = 1;
			solve(i * 10 + j);
			vec[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i < 10; i++) vec[i] = 1, solve(i), vec[i] = 0;
	cout << ans;
}
