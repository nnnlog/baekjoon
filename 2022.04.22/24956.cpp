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

    const int mod = 1e9 + 7;

    int n; cin >> n;
    string s; cin >> s;
    s.insert(s.begin(), '_');

    vector<vi> dp(n + 1, vi(5));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            dp[i] = dp[i - 1];
            if (s[i] == 'W') dp[i][1] += dp[i - 1][0];
            if (s[i] == 'H') dp[i][2] += dp[i - 1][1];
            if (s[i] == 'E') dp[i][3] += dp[i - 1][2], dp[i][4] += (dp[i - 1][3] + dp[i - 1][4]) % mod;
            for (int &k : dp[i]) k %= mod;
        }
    }

    cout << dp[n][4];
}