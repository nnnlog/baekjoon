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

int mod(string &num, int a)
{
    // Initialize result
    ll res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<string> vec(n);
    for (auto &i: vec) cin >> i;
    vector<vi> graph(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    function<string(int, int, int)> dfs = [&](int u, int prv, int end) {
        string ret = vec[u];
        if (u == end) return ret;
        for (int v: graph[u]) {
            if (v != prv) ret += dfs(v, u, end);
        }
        if (ret == vec[u]) return string("");
        return ret;
    };
    while (q--) {
        int a, b;
        cin >> a >> b;
        string ans = dfs(--a, -1, --b);
        cout << mod(ans, 1e9 + 7) << "\n";
    }
}