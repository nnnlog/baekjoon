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

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
    }

    int r = 0, b = 0, g = 0;
    while (m--) {
        int x, y; cin >> x >> y;
        char c; cin >> c;
        if (c == 'R') r++;
        if (c == 'B') b++;
        if (c == 'G') g++;
    }

    if (g % 2) b--;
    cout << "jhna" << (r > b ? 'h' : 'n') << "917";
}
