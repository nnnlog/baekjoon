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

	ll n, k; cin >> n >> k;
	unordered_map<ll, ll> L;
	vector<ll> sum(n + 1);
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		int a; cin >> a;
		sum[i] = sum[i - 1] + a;
		
		L[sum[i - 1] - (i - 1) * k]++;
		ll R = sum[i] - i * k;
		if (L.count(R)) ans += L[R];
	}

	cout << ans;
}
