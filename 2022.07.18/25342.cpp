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

//    for (int n = 3; n <= 40; n++) {
//        pair<int, pair<int, pii>> ans;
//        for (int i = 1; i <= n; i++) {
//            for (int j = i + 1; j <= n; j++) {
//                for (int k = j + 1; k <= n; k++) {
//                    ans = max(ans, {lcm(i, lcm(j, k)), {i, {j, k}}});
//                }
//            }
//        }
//        cout << n << " : " << ans.second.first << " " << ans.second.second.first << " " << ans.second.second.second << " > " << ans.first << "\n";
//    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll ans = 0;
        for (int i = max(1, n - 4); i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    ans = max(ans, lcm(lcm((ll)i, j), k));
                }
            }
        }

        cout << ans << "\n";
    }
}
