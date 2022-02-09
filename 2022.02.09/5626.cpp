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

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vi vec(n);
    for (int &i : vec) cin >> i;

    if (vec.front() > 0 || vec.back() > 0 || *max_element(all(vec)) > 5000) return cout << 0, 0;
    vec.front() = vec.back() = 0;

    auto solve = [&](int a, int b, int sz) {
        if (a > b) swap(a, b);

        vi dp(5002);
        dp[a] = 1;
        for (int i = 1; i <= sz; i++) {
            auto tmp = vi(5002);
            for (int j = 0; j <= 5000; j++)
                tmp[j] = (ll(j ? dp[j - 1] : 0) + dp[j] + dp[j + 1]) % mod;
            tmp.swap(dp);
        }
        return dp[b];
    };

    ll ans = 1;
    pii prv = {0, 0};
    for (int i = 1; i < n; i++) {
        if (vec[i] == -1) continue;

        ans *= solve(vec[i], prv.second, i - prv.first);
        ans %= mod;
        if (!ans) break;
        prv = {i, vec[i]};
    }
    cout << ans;
}
