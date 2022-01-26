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

const int mod = 9901;

int dp[1000001][2];

int solve(int n, int k) {
    int &ret = dp[n][k];
    if (ret) return ret;
    if (n == 1) return ret = 1;
    if (!k) return ret = (2 * solve(n - 1, 0) + 1) % mod;
    int i = n - int(round(sqrt(2 * n + 1))) + 1;
    return ret = (2 * solve(i, 1) + solve(n - i, 0)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    solve(n, 1);
    cout << solve(n, 1);
}
