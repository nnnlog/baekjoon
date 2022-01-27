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

    int n; cin >> n;
    vpii vec(n);
    for (auto &[a, b] : vec) cin >> a;
    for (auto &[a, b] : vec) cin >> b;
    map<int, int> dp;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        auto nxt = dp;
        for (const auto &[k, v] : dp) {
            int g = gcd(k, vec[i].first);
            if (!nxt[g]) nxt[g] = 1e9;
            nxt[g] = min(nxt[g], v + vec[i].second);
        }
        dp.swap(nxt);
    }

    cout << (!dp[1] ? -1 : dp[1]);
}
