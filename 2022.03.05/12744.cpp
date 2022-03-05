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

    int n;
    cin >> n;
    vpii vec(n);
    for (auto &[a, b]: vec) {
        char c;
        cin >> a >> c;
        b = c == '+';
    }

    auto state = [&](vpii vec) {
        string ret = "";
        for (const auto &[a, b]: vec) {
            ret += to_string(a) + to_string(b);
        }
        return ret;
    };

    string ok = "";
    for (int i = 1; i <= n; i++) ok += to_string(i) + "1";

    queue<pair<vpii, int>> Q;
    unordered_map<string, int> vis;

    if (ok == state(vec)) return cout << 0, 0;

    Q.emplace(vec, 0);
    vis[state(vec)] = 0;

    while (!Q.empty()) {
        auto v = Q.front().first;
        int step = Q.front().second + 1;
        Q.pop();

        for (int i = 0; i < n; i++) {
            auto tmp = v;
            reverse(tmp.begin(), tmp.begin() + i + 1);
            for (int j = 0; j <= i; j++) tmp[j].second = !tmp[j].second;
            string s = state(tmp);
            if (vis[s]) continue;
            vis[s] = 1;
            if (s == ok) return cout << step, 0;
            Q.emplace(tmp, step);
        }
    }
}
