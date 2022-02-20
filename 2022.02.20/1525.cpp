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
/*
int hashing(const vector<vi> &vec) {
    int ret = 0;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            ret = ret * 10 + vec[i][j];
        }
    }
    return ret;
}
*/
void solve() {
    /*vector<vi> vec(3, vi(3));
    for (auto &v : vec) {
        for (auto &i : v) {
            char c; cin >> c;
            if (c == '#') i = 0;
            else i = c - '0';
        }
    }*/
    string s(9, 0);
    for (char &i : s) cin >> i;

    if (s == "123456780") {
        cout << "0\n";
        return;
    }

    queue<pair<string, pii>> Q;
    unordered_map<string, int> vis;
    vis[s] = 1;
    int idx = s.find('0');
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
            if (curr == "123456780") {
                cout << step + 1 << "\n";
                return;
            }
            if (!vis[curr]) {
                Q.push({curr, {x * 3 + y, step + 1}});
                vis[curr] = 1;
            }
            swap(curr[nxt_idx], curr[curr_idx]);
        }
    }
    cout << "-1";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    while (T--) solve();
}
