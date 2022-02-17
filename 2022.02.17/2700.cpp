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

int ccw(int a, int b, int c, int d, int e, int f) {
    return a * d + c * f + b * e - b * c - d * e - a * f;
}

int in(const vpii &vec, int x, int y) {
    for (int i = 1; i <= vec.size(); i++) {
        if (ccw(x, y, vec[i - 1].first, vec[i - 1].second, vec[i % vec.size()].first,
                vec[i % vec.size()].second) >= 0) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vpii vec(n);
        for (auto &[a, b]: vec) cin >> a >> b;

        vector<pair<int, pii>> ans;
        for (int y = 30; y >= -30; y--) {
            int mn = 1e9, mx = -1e9;
            for (int x = -30; x <= 30; x++) if (in(vec, x, y)) mn = min(mn, x), mx = max(mx, x);
            if (mn <= mx) ans.push_back({y, {mn, mx}});
        }

        cout << ans.size() << "\n";
        for (const auto &[a, bc] : ans) cout << a << " " << bc.first << " " << bc.second << "\n";
    }
}
