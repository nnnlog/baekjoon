#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m = 1 << n;
    vector<vector<int>> graph(m + 1);
    for (int i = 2; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    vector<pair<int, int>> vis(m + 1);
    set<int> idx;
    function<pair<int, int>(int)> dfs1 = [&](int u) {
        pair<int, int> &ret = vis[u];
        if (ret.first) return ret;
        ret = {1, 0};
        for (int v: graph[u]) {
            if (vis[v].first) {
                idx.erase(v);
            }
            auto k = dfs1(v);
            ret.first += k.first;
            ret.second++;
        }
        return ret;
    };
    for (int i = 1; i <= m; i++) {
        if (vis[i].first) continue;
        auto r = dfs1(i);
        idx.insert(i);
    }
    vector<pair<int, int>> comp;
    for (int i : idx) comp.push_back(dfs1(i));
    assert(idx.size() == 2);

    vector<pair<int, int>> ans;
    int curr_idx;
    pair<int, int> current;
    function<void(int, int)> dfs2 = [&](int u, int scale) {
        vector<int> ok(scale);
        auto info = vis[u];
        if ((1 << scale) == info.first) return;
        int valid = 1;
        unordered_map<int, int> error;
        for (int v: graph[u]) {
            if ((1 << vis[v].second) != vis[v].first) {
                error[v] = 1;
            }
        }
        for (int v: graph[u]) {
//            dfs2(v, scale - 1);
            dfs2(v, vis[v].second);
            if ((error.empty() || error.count(v)) && (vis[v].first) + current.first == (1 << (1 + vis[v].second))) dfs2(v, vis[v].second + 1);
            if (ok[vis[v].second]) valid = 0;
            else ok[vis[v].second] = 1;
        }
        if (valid && !ok[current.second] && (1 << (1 + info.second)) == info.first + current.first) {
            ans.emplace_back(u, curr_idx);
        }
    };
    curr_idx = *idx.begin();
    current = vis[curr_idx];
    dfs2(*idx.rbegin(), n);

    curr_idx = *idx.rbegin();
    current = vis[curr_idx];
    dfs2(*idx.begin(), n);

//    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    assert(1 <= ans.size() && ans.size() <= 2);
//    cout << "A\n\n";
    for (auto [a, b] : ans) cout << a << " " << b << "\n";
}
