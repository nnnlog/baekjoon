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
    string s = "12345678#";
    queue<pair<string, pii>> Q;
    unordered_map<string, int> vis;
    vis[s] = 0;
    int idx = s.find('#');
    Q.push({s, {idx, 0}});
    while (!Q.empty()) {
        auto front = Q.front(); Q.pop();
        string curr = front.first;
        int a = front.second.first / 3, b = front.second.first % 3;
        int step = front.second.second;
        int curr_idx = a * 3 + b;
        for (const auto &[dx, dy] : vpii{
                {-1, 0},
                {1, 0},
                {0, -1},
                {0, 1}
        }) {
            int x = a + dx, y = b + dy;
            if (x < 0 || y < 0 || x >= 3 || y >= 3) continue;
            int nxt_idx = x * 3 + y;
            swap(curr[nxt_idx], curr[curr_idx]);
            if (!vis.count(curr)) {
                Q.push({curr, {x * 3 + y, step + 1}});
                vis[curr] = step + 1;
            }
            swap(curr[nxt_idx], curr[curr_idx]);
        }
    }

    int T; cin >> T;
    while (T--) {
        string a, b, c; cin >> a >> b >> c;
        a = a + b + c;
        if (vis.count(a)) cout << vis[a];
        else cout << "impossible";
        cout << "\n";
    }
}
