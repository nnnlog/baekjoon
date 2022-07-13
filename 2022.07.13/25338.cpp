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

    cout << fixed;
    cout.precision(15);

    ld a, b, c, d;
    cin >> a >> b >> c >> d;

    auto calc = [&](ld x) {
        return max(a * (x - b) * (x - b) + c, d);
    };

    int ans = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ld u, v; cin >> u >> v;
        if (b <= v && abs(calc(v) - u) < 1e-7) ans++;
    }

    cout << ans;
}
