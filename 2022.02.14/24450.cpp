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

vector<vi> sum;

int get_sum(int a, int b, int x, int y) {
    return sum[x][y] - sum[x][b - 1] - sum[a - 1][y] + sum[a - 1][b - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w;
    cin >> h >> w;
    sum.assign(h + 1, vi(w + 1));
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            cin >> sum[i][j];
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }

    int ans = -1;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            int curr = get_sum(1, 1, i, j);
            vi x = {0, i}, y = {0, j};
            for (int a = i + 1; a <= h; a++) {
                if (get_sum(x.back() + 1, 1, a, j) == curr) x.push_back(a);
            }
            for (int b = j + 1; b <= w; b++) {
                if (get_sum(1, y.back() + 1, i, b) == curr) y.push_back(b);
            }
            int ok = x.back() == h && y.back() == w;
            for (int a = 1; a < x.size(); a++) {
                for (int b = 1; b < y.size(); b++) {
                    int tmp = get_sum(x[a - 1] + 1, y[b - 1] + 1, x[a], y[b]);
                    if (curr && curr != tmp) ok = 0;
                    else curr = tmp;
                }
            }
            if (ok) ans++;
        }
    cout << ans;
}
