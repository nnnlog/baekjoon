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

const int mod = 11092019;

vpll seg(4e6);

pll upd(int node, int start, int end, int k, pll v) {
    if (!(start <= k && k <= end)) return seg[node];
    if (start == end) return seg[node] = v;
    int mid = (start + end) >> 1;
    pll A = upd(node * 2, start, mid, k, v), B = upd(node * 2 + 1, mid + 1, end, k, v);
    if (A.first != B.first) {
        if (A.first > B.first) return seg[node] = A;
        else return seg[node] = B;
    }
    return seg[node] = {A.first, (A.second + B.second) % mod};
}

pll qry(int node, int start, int end, int l, int r) {
    if (end < l || r < start) return {0, 0};
    if (l <= start && end <= r) return seg[node];
    int mid = (start + end) >> 1;
    pii A = qry(node * 2, start, mid, l, r), B = qry(node * 2 + 1, mid + 1, end, l, r);
    if (A.first != B.first) {
        if (A.first > B.first) return A;
        else return B;
    }
    return {A.first, (A.second + B.second) % mod};
}

vi vec;
vector<vi> graph;

pll ans;
void dfs(int u) {
    pll origin = qry(1, 0, 1e6, vec[u], vec[u]);

    pll mx = qry(1, 0, 1e6, 0, vec[u]);
    pll nxt = {mx.first + 1, max(1LL, mx.second)};
    if (ans.first < nxt.first) ans = {nxt.first, 0};
    if (ans.first == nxt.first) ans.second += nxt.second, ans.second %= 11092019;
    upd(1, 0, 1e6, vec[u], nxt);

    for (int v : graph[u]) dfs(v);

    upd(1, 0, 1e6, vec[u], origin);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vec.resize(n + 1);
    graph.resize(n + 1);
    for (int &i : vec | views::drop(1)) cin >> i;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        graph[p].push_back(i);
    }
    dfs(1);
    cout << ans.first << " " << ans.second;
}
