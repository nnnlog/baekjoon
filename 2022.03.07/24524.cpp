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

    string s, t;
    cin >> s >> t;
    vector<set<int>> pos('z' + 1);
    for (int i = 0; i < s.size(); i++) pos[s[i]].insert(i);
    int ans = 0, fail = 0;
    while (!fail) {
        int last = -1;
        for (char c: t) {
            auto it = pos[c].upper_bound(last);
            if (it == pos[c].end()) {
                fail = 1;
                break;
            }
            last = *it;
            pos[c].erase(it);
        }
        if (!fail) ans++;
    }
    cout << ans;
}
