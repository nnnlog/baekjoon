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

    int x, y; cin >> x >> y;
    int n; cin >> n;

    vpii vec = {{x, y}};
    while (n--) {
        int a, b; cin >> a >> b;
        vec.emplace_back(a, b);
    }

    cout << fixed;
    cout.precision(15);

    ld ans = 1e9;
    for (const auto &[a, b] : vec) ans = min(ans, a * 1000 / ld(b));
    cout << ans;
}
