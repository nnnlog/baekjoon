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

vl UF, cnt;

int find(int a) {
    return UF[a] = a == UF[a] ? a : find(UF[a]);
}

ll curr;

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
        curr -= cnt[b] * (cnt[b] - 1) / 2;
        curr -= cnt[a] * (cnt[a] - 1) / 2;
        cnt[a] += cnt[b];
        curr += cnt[a] * (cnt[a] - 1) / 2;
        UF[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    UF.resize(n + 1);
    iota(all(UF), 0);
    cnt.assign(n + 1, 1);
    vector<pair<int, pii>> graph;
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        graph.push_back({w, {a, b}});
    }
    sort(all(graph), greater<>());
    ll ans = 0;
    for (const auto &[w, uv]: graph) {
        merge(uv.first, uv.second);
        ans += curr * w;
        ans %= int(1e9);
    }
    cout << ans;
}
