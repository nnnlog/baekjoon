#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    int h, w, c;
    cin >> h >> w >> c;
    stack<pair<int, int>> q;
    for (int i = 1; i <= c; i++) {
        int a;
        cin >> a;
        q.push({i, a});
    }

    vector<vector<int>> ans(w, vector<int>(h));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++) {
            auto f = q.top();
            q.pop();
            ans[x][y] = f.first;
            if (--f.second) q.push({f.first, f.second});
        }


    for (int y = 0; y < h; y++) {
        if (y % 2) for (int x = 0; x < w; x++) cout << ans[x][y];
        else for (int x = w - 1; x >= 0; x--) cout << ans[x][y];

        cout << "\n";
    }

}