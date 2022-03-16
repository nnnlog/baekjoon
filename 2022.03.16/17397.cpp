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

    int n, m;
    cin >> n >> m;

    vi vec(n + 1);
    for (int &i : vec | views::drop(1)) cin >> i;

    vector<vector<vi>> dp(n + 1, vector<vi>(11, vi(m + 1, 1e9)));

    dp[1][vec[1]][m] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = vec[i - 1]; j <= 10; j++) {
            for (int k = 0; k <= m; k++) {
                for (int x = 0; x <= max(0, j - vec[i]); x++) {
                    if (k + x > m) continue;
                    dp[i][vec[i] + x][k] = min(dp[i][vec[i] + x][k], dp[i - 1][j][k + x] + int(pow(max(0, j - vec[i] - x), 2)));
                }
            }
        }
    }

    int ans = 1e9;
    for (int j = vec[n]; j <= 10; j++) {
        for (int k = 0; k <= m; k++) {
            ans = min(ans, dp[n][j][k]);
        }
    }

    cout << ans;
}
