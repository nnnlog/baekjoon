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


    int n;
    cin >> n;

    vector<vi> vec(n, vi(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> vec[i][j];

    int tmp = 0;
    string s; cin >> s;
    for (int i = 0; i < n; i++) tmp |= (s[i] == 'Y') << i;

    vi dp(1 << n, 1e9);
    dp[tmp] = 0;

    int ok, ans = 1e9;
    cin >> ok;
    
    if (__builtin_popcount(tmp) >= ok) return cout << 0, 0;

    for (int i = tmp + 1; i < (1 << n); i++) {
        dp[i] = 1e9;
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                if (!(i & (1 << k))) continue;
                dp[i] = min(dp[i], dp[i ^ (1 << k)] + vec[j][k]);
            }
        }
        if (__builtin_popcount(i) >= ok) ans = min(ans, dp[i]);
    }

    cout << (ans == 1e9 ? -1 : ans);
}
