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

int ccw(pii a, pii b, pii c) {
    return abs(a.first * b.second + b.first * c.second + c.first * a.second
        - a.second * b.first - b.second * c.first - c.second * a.first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1) {
        int n; cin >> n;
        if (!n) break;
        vpii vec(n);
        char _;
        for (auto &[a, b] : vec) cin >> _ >> a >> b;
        int ans = 0;
        vi sel;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sz = ccw(vec[i], vec[j], vec[k]);
                    if (ans >= sz) continue;
                    int f = 0;
                    for (int l = 0; l < n; l++) {
                        if (i == l || j == l || k == l) continue;
                        //cout << i << " " << j << " " << k << " " << l << " " << ccw(vec[i], vec[l], vec[k]) + ccw(vec[j], vec[l], vec[k]) + ccw(vec[i], vec[l], vec[j]) << " " << sz << endl;
                        if (ccw(vec[i], vec[l], vec[k]) + ccw(vec[j], vec[l], vec[k]) + ccw(vec[i], vec[l], vec[j]) <= sz) {
                            f = 1;
                            break;
                        }
                    }
                    if (!f) {
                        ans = sz;
                        sel = {i, j, k};
                    }
                }
            }
        }

        assert(!sel.empty());
        cout << char(sel[0] + 'A') << char(sel[1] + 'A') << char(sel[2] + 'A') << "\n";
    }
}
