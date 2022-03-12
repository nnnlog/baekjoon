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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vi> vec(n, vi(m));
    pii A, B;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 1) A = {i, j};
            if (vec[i][j] == 2) B = {i, j};
        }
    }

    vector<vpii> vis(n, vpii(m));
    queue<pair<pii, int>> Q;
    vis[A.first][A.second] = {1, 1};
    vis[B.first][B.second] = {2, 1};
    Q.push({A, 1});
    Q.push({B, 1});
    while (!Q.empty()) {
        auto f = Q.front();
        Q.pop();
        int a = f.first.first, b = f.first.second;
        int c = f.second + 1;
        if (vis[a][b].first == 3) continue;
        for (const auto &[dx, dy]: vpii{
                {-1, 0},
                {1,  0},
                {0,  -1},
                {0,  1}
        }) {
            int x = a + dx, y = b + dy;
            if (x < 0 || x >= n || y < 0 || y >= m || vec[x][y] == -1 || (vis[x][y].second && vis[x][y].second < c)) continue;
            if (vis[x][y].first) {
                if (vis[x][y].first != vis[a][b].first && c == vis[x][y].second) vis[x][y].first = 3;
            } else {
                vis[x][y] = {vis[a][b].first, c};
                Q.push({{x, y}, c});
            }
        }
    }

    int x = 0, y = 0, z = 0;
    for (const auto &v: vis)
        for (auto [a, _]: v) {
            if (a == 1) x++;
            if (a == 2) y++;
            if (a == 3) z++;
        }
    cout << x << " " << y << " " << z;
}
