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

    vector<vi> vec(5, vi(5));
    for (auto &v: vec)
        for (int &i: v) cin >> i;

    vi vis(25, -1);
    queue<pii> Q;
    {
        int a, b; cin >> a >> b;
        vis[a * 5 + b] = 0;
        Q.emplace(a, b);
    }
    while (!Q.empty()) {
        pii f = Q.front();
        Q.pop();
        int a = f.first, b = f.second;
//        cout << a << " " << b << "\n";
        if (vec[a][b] == 1) {
            cout << vis[a * 5 + b];
            return 0;
        }
        for (auto &[dx, dy]: vpii{
                {-1, 0},
                {1, 0},
                {0, -1},
                {0, 1}
        }) {
            int x = a + dx, y = b + dy;
            if (x < 0 || x >= 5 || y < 0 | y >= 5) continue;
            if (vec[x][y] != -1 && vis[x * 5 + y] == -1) {
                vis[x * 5 + y] = vis[a * 5 + b] + 1;
                Q.emplace(x, y);
            }
        }
    }
    cout << -1;
}
