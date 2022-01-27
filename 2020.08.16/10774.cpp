#include <bits/stdc++.h>

using namespace std;

vector<int> info(1000001), vis(1000001);

int sz(char c) {
    if (c == 'L') return 2;
    if (c == 'M') return 1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int j, a; cin >> j >> a;
    for (int i = 1; i <= j; i++) {
        char c; cin >> c;
        info[i] = sz(c);
    }

    int ans = 0;
    while (a--) {
        char c; cin >> c;
        int i; cin >> i;
        if (!vis[i] && sz(c) <= info[i]) {
            ans++;
            vis[i] = 1;
        }
    }

    cout << ans;
}
