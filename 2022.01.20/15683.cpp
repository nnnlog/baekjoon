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

vpii dxdy = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
};
vector<vi> view = {
        {},
        {0},
        {0, 2},
        {0, 1},
        {0, 1, 2},
        {0, 1, 2, 3},
};

vi rotate(const vi &v, int k) {
    vi ret = v;
    for (int &i : ret) i += k, i %= 4;
    sort(all(ret));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vi> vec(n, vi(m));
    vpii cctv;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            if (0 < vec[i][j] && vec[i][j] < 6) cctv.emplace_back(i, j);
        }

    int ans = n * m;
    for (int bit = 0; bit <= (1 << (cctv.size() * 2)); bit++) {
        auto tmp = vec;
        for (int i = 0; i < cctv.size(); i++) {
            int k = (bit >> (i * 2)) & 3;
            auto curr = rotate(view[vec[cctv[i].first][cctv[i].second]], k);
            for (int f : curr) {
                int x = cctv[i].first, y = cctv[i].second;
                int dx = dxdy[f].first, dy = dxdy[f].second;
                while (x >= 0 && x < n && y >= 0 && y < m && tmp[x][y] != 6) {
                    if (!tmp[x][y]) tmp[x][y] = -1;
                    x += dx, y += dy;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cnt += tmp[i][j] == 0;
        ans = min(ans, cnt);
    }

    cout << ans;
}
