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

int UF[200001];
int find(int a) {
    return UF[a] = UF[a] == a ? a : find(UF[a]);
}
void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) UF[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<tuple<int, int, int>>> graph(n + 1);
    vpii edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].emplace_back(b, c, i);
        graph[b].emplace_back(a, c, i);
        edges[i] = {a, b};
    }

    vi A(n + 1), B(n);
    for (int &i : A | views::drop(1)) cin >> i;
    for (int &i : B) cin >> i;
    sort(all(B), greater<>());

    iota(UF, UF + n, 0);

    function<void(int, int)> dfs = [&](int u, int prv) {
        unordered_map<int, vi> colors;
        for (const auto &[v, color, idx] : graph[u]) {
            colors[color].push_back(idx);
            if (v == prv) continue;
            dfs(v, u);
        }
        for (const auto &[_, v] : colors) {
            for (int i = 0; i < v.size() - 1; i++) merge(v[i], v[i + 1]);
        }
    };
    dfs(1, 0);

    unordered_map<int, set<int>> group;
    for (int i = 0; i < n - 1; i++) {
        int k = find(i);
        group[k].insert(edges[i].first);
        group[k].insert(edges[i].second);
    }

    vi calc(n + 1), cnt(n + 1);
    for (const auto &[k, S] : group) {
        for (int i: S) calc[k] += A[i];
        for (int i: S) cnt[i] += calc[k];
    }

    vpii srt;
    for (int i = 1; i <= n; i++) srt.emplace_back(cnt[i], i);
    sort(all(srt));

    vi score(n + 1);
    for (int i = 0; i < n; i++) score[srt[i].second] = B[i];

    {
        ll ans = 0;
        for (const auto &[k, S] : group) {
            ll b = 0;
            for (int i : S) {
                b += score[i];
            }
            ans += calc[k] * b;
        }
        cout << ans << "\n";
    }

    reverse(all(B));
    for (int i = 0; i < n; i++) score[srt[i].second] = B[i];
    {
        ll ans = 0;
        for (const auto &[k, S] : group) {
            ll b = 0;
            for (int i : S) {
                b += score[i];
            }
            ans += calc[k] * b;
        }
        cout << ans << "\n";
    }
}
