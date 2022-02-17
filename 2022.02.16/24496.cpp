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

void yes() {
    cout << "yes\n";
}
void no() {
    cout << "no\n";
}
void yes(bool y) {
    if (y) yes();
    else no();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vi vec(n);
        for (int &i : vec) cin >> i;

        auto solve = [&](ll mid) -> ll {
            if (mid < 0) return -1;
            ll minus = vec[0] - mid;
            ll ans = minus;
            for (int i = 1; i < n - 1; i++) {
                if (vec[i] - minus < mid) return -1;
                else minus = vec[i] - minus - mid, ans += minus;
            }
            if (vec.back() - minus != mid) return -1;
            return ans * 2;
        };

        ll A = 0, B = 0;
        ll mn = 1e9, sum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                A += vec[i];
                sum += vec[i];
                mn = min(mn, sum);
            } else {
                B += vec[i];
                sum -= vec[i];
                if (A > B) {
                    cout << "-1\n";
                    goto bye;
                }
            }
        }

        cout << solve(mn) << "\n";
        bye:;
    }
}