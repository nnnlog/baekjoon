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

    int n, k; cin >> n >> k;
    vi ok('z' + 1), curr('z' + 1);
    string a, s; cin >> a >> s;
    for (char c : a) ok[c]++;
    for (int i = 0; i < n - 1; i++) curr[s[i]]++;
    int ans = 0;
    for (int i = n - 1; i < k; i++) {
        curr[s[i]]++;
        if (i - n >= 0) curr[s[i - n]]--;
        ans += ok == curr;
    }
    cout << ans;
}
