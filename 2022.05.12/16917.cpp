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
    
    ll ans = 1e18;
	
	ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    for (ll i = 0; i <= max(x, y) * 2; i += 2) {
        ll u = max(0LL, x - i / 2), v = max(0LL, y - i / 2);
        ans = min(ans, u * a + v * b + i * c);
    }
    cout << ans;
}
