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
    vector<vi> dp(51, vi(51, -1));
    dp[0][0] = 0;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 50; i - a >= 0; i--) {
            for (int j = 50; j - b >= 0; j--) {
                if (dp[i - a][j - b] >= 0) dp[i][j] = max(dp[i][j], dp[i - a][j - b] + c);
            }
        }
    }

    vpii ans;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        ans.emplace_back(max(0, dp[a][b]), i);
    }
    sort(all(ans));
    for (const auto &[a, b]: ans) cout << b << " " << a << "\n";
}
