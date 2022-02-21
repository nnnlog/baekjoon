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

    int n, k;
    cin >> n >> k;
    vi vec(n + 1);
    for (int &i: vec | views::drop(1)) cin >> i;
    vector<vl> dp(n + 1, vl(n + 1));
    vl mx(n + 1);
    ll any = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = max(1, i - k + 1); j < i; j++) dp[i][j] = max(any, mx[j] + vec[i]);
        dp[i][i] = any + vec[i];
        {
            int ok = i - k + 1;
            for (int j = 1; j <= i; j++) {
                if (ok >= 1) {
                    if (ok < j) mx[j] = max(mx[j], dp[j][ok]);
                }
            }
        }
        {
            int ok = i - k + 1;
            for (int j = 1; j <= ok; j++) any = max(any, dp[ok][j]);
        }

        mx[i] = max(mx[i], dp[i][i]);
    }

    ll ans = 0;
    for (auto &v: dp) ans = max(ans, *max_element(all(v)));
    cout << ans;
}
