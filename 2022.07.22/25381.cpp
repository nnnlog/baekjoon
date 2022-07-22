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

    string s; cin >> s;
    set<int, greater<>> a, b, c;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') a.insert(i);
        if (s[i] == 'B') b.insert(i);
        if (s[i] == 'C') c.insert(i);
    }
    int ans = 0;
    while (!a.empty()) {
        int i = *a.begin();
        if (b.empty()) break;
        int j = *b.begin();
        if (i < j) {
            a.erase(i);
            b.erase(j);
            ans++;
        } else a.erase(i);
    }
    while (!b.empty()) {
        int i = *b.begin();
        if (c.empty()) break;
        int j = *c.begin();
        if (i < j) {
            b.erase(i);
            c.erase(j);
            ans++;
        } else b.erase(i);
    }
    cout << ans;
}
