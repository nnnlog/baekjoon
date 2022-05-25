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

    string str; cin >> str;

    int mx = 0;
    map<char, int> mp;
    for (auto c : str) mx = max(mx, ++mp[c]);

    int n = str.size();
    int sz = n;
//	if (mx * 2 > sz + 1) return cout << -1, 0;

    string ans;

    for (int i = 0; i < n; i++) {
        char ok = 'z' + 1;
        for (const auto &[a, b] : mp) {
            if (i * 2 < n || a != ans[n - i - 1]) {
                if (i * 2 < n && b * 2 > n + 1) {
                    ok = a;
                    break;
                }
                if (ok > a) ok = a;
            }
        }

        if (ok > 'z') {
            cout << -1;
            return 0;
        }

        ans.push_back(ok);
        sz--;
        if (!--mp[ok]) mp.erase(ok);
    }

    cout << ans;
}
