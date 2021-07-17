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

	int n, total = 0; cin >> n;
	vi vec(n);
	for (int &i : vec) cin >> i, total += i;
	vec.pop_back();
	if (total % 4) {
		cout << 0;
		return 0;
	}
	ll ans = 0;
	ll a = 0, b = 0;
	int sum = 0;
	for (const int i : vec) {
		sum += i;
		if (sum == 3LL * total / 4) ans += b;
		if (sum == total / 2) b += a;
		if (sum == total / 4) ++a;
	}
	cout << ans;
}
