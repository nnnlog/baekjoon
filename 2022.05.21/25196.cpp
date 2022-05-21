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

    ll av, as, ae;
    cin >> av >> as >> ae;

    ll bv, bs, be;
    cin >> bv >> bs >> be;

    ll cv, cs, ce;
    cin >> cv >> cs >> ce;

    auto in = [&](ll t) {
        ll a = t % av;
        if (!(as <= a && a <= ae)) return 0;
        ll b = t % bv;
        if (!(bs <= b && b <= be)) return 0;
        ll c = t % cv;
        if (!(cs <= c && c <= ce)) return 0;
        return 1;
    };

    ll ans = 1e18;
//    cout << ll(av) * bv * cv << "\n";
    ll L = lcm(av, lcm(bv, cv));
//    cout << lcm(bv, cv) << " = " << bv * cv << " " << L << "\n";
//    cout << (av) * bv * cv / gcd(bv * cv, av) << "\n";
    for (ll i = as; i < L + as; i += av) {
        if (in(i)) {
            ans = min(ans, i);
            break;
        }
    }
    for (ll i = bs; i < L + bs; i += bv) {
        if (in(i)) {
            ans = min(ans, i);
            break;
        }
    }
    for (ll i = cs; i < L + cs; i += cv) {
        if (in(i)) {
            ans = min(ans, i);
            break;
        }
    }
    if (ans == 1e18) ans = -1;
    cout << ans;
}
