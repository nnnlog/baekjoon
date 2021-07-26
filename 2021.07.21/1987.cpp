#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
 
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
char mp[21][21];
int vis[21][21], ans;
char ok[200];
void solve(int x, int y, int cnt) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        char nxt = mp[xx][yy];
        if (ok[nxt]) continue;
        //if (vis[xx][yy] > cnt + 1) continue;
        ok[nxt] = 1;
        vis[xx][yy] = cnt + 1;
        ans = max(ans, cnt + 1);
        solve(xx, yy, cnt + 1);
        ok[nxt] = 0;
    }
}
int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cin >> n >> m;
 for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> mp[i][j];
 ok[mp[1][1]] = 1;
 vis[1][1] = ans = 1;
 solve(1, 1, 1);
 cout << ans;
}