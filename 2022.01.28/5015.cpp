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

    string pattern; cin >> pattern;
    pattern.insert(pattern.begin(), 0);
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        s.insert(s.begin(), 0);
        vector<vi> dp(pattern.size(), vi(s.size()));
        dp[0][0] = 1;
        for (int i = 1; i < pattern.size(); i++) {
            for (int j = 1; j < s.size(); j++) {
                if (pattern[i] == s[j]) dp[i][j] = dp[i - 1][j - 1];
                if (pattern[i] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i - 1][j - 1];
                    dp[i][j - 1] |= dp[i - 1][j - 1];
                }
            }
        }
        if (dp.back().back()) cout << s.substr(1) << "\n";
    }
}
