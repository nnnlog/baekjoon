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

string s;

int n, dp[50][50];

int _solve(int l, int r) {
    if (l < 0 || r >= n) return max(l + 1, n - r);
    int &ret = dp[l][r];
    if (ret >= 0) return ret;
    if (s[l] == s[r]) return ret = _solve(l - 1, r + 1);
    else return ret = min(_solve(l - 1, r + 1), min(_solve(l - 1, r), _solve(l, r + 1))) + 1;
}

int solve() {
    int ret = 1e9;
    for (int l = 0; l < n; l++) {
        for (auto &v : dp)
            for (auto &i : v) i = -1;

        ret = min(ret, _solve(l, l));
        
        for (auto &v : dp)
            for (auto &i : v) i = -1;
        ret = min(ret, _solve(l, l + 1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s;
    n = s.size();
    int ans = solve();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            //if (s[i] == s[j]) continue;
            swap(s[i], s[j]);
            ans = min(ans, solve() + 1);
            //cout << s << " " << solve() + 1 << "\n";
            swap(s[i], s[j]);
        }
    }
    cout << ans;
}
