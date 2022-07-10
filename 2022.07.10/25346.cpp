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

    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mp[a] = 1;
    }

    int ans = 0;
    for (; mp.count(ans); ans++);

    if (!ans) cout << 0;
    else if (ans == 1 && mp.size() == 1) cout << 1;
    else cout << ans + 2;
}
