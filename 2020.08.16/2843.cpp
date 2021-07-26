#include <bits/stdc++.h>

using namespace std;

int parent[300001], vis[300001], UF[300001], cycle[300001];
stack<string> ans;
stack<pair<bool, int>> query;

int find(int a) {
    return UF[a] = a == UF[a] ? a : find(UF[a]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        UF[i] = i;

        int a;
        cin >> a;
        parent[i] = a;
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) { //print
            query.emplace(0, b);
        } else { //merge
            vis[b] = 1;
            query.emplace(1, b);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && parent[i]) query.emplace(1, i);
    }

    while (!query.empty()) {
        auto top = query.top();
        query.pop();
        if (!top.first) ans.push(cycle[find(top.second)] ? "CIKLUS" : to_string(find(top.second)));
        else {
            int par = find(parent[top.second]), child = find(top.second);
            if (par == child || cycle[par] || cycle[child]) {
                cycle[par] = cycle[child] = true;
            } else {
                UF[child] = par;
            }
        }
    }

    while (!ans.empty()) {
        cout << ans.top() << "\n";
        ans.pop();
    }
}
