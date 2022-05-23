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

vector<vector<pair<int, pii>>> go;

int solve(int day, int pos) {
    auto it = lower_bound(all(go[pos]), make_pair(day, pii{0, 0}));
    if (it == go[pos].end()) return pos;
    int &ret = it->second.second;
    if (ret) return ret;
    return ret = solve(it->first + 1, it->second.first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    go.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        go[a].push_back({i, {b, 0}});
    }

    for (int i = 1; i <= n; i++) cout << solve(0, i) << " ";
}
