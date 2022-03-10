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

    ll h;
    cin >> h;
    auto get_sect = [&](ll a) {
        ll s = 1, e = h;
        while (s < e) {
            ll mid = (s + e) >> 1;
            if (mid * (mid + 1) / 2 < a) s = mid + 1;
            else e = mid;
        }

        ll l = 1, r = h + 1;
        r -= s - 1;

        ll remain = a - (s - 1) * s / 2 - 1;
        l += remain, r += remain;

        return pll{l, r};
    };

    ll q, r;
    cin >> q >> r;
    vld sum(h + 3);
    while (q--) {
        ll a, b;
        cin >> a >> b;
        auto tmp = get_sect(a);
        ld ok = ld(b) / (tmp.second - tmp.first + 1);
        sum[tmp.first] += ok;
        sum[tmp.second + 1] -= ok;
    }
    partial_sum(all(sum), sum.begin());
    partial_sum(all(sum), sum.begin());

    cout << fixed;
    cout.precision(16);

    while (r--) {
        ll a, b; cin >> a >> b;
        cout << sum[b] - sum[a - 1] << "\n";
    }
}
