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

    int T; cin >> T;
    while (T--) {
        int n, s; cin >> n >> s;
        vpii vec(n);
        for (auto &[a, b] : vec) cin >> a;
        for (auto &[a, b] : vec) cin >> b;
        map<int, vi> mp;
        mp[s] = {};
        for (const auto &[a, b] : vec) mp[a].push_back(b);
        ll ans = 0;
        priority_queue<pii> pq;
        for (const auto &[k, v] : mp) {
            for (const auto &i : v) pq.emplace(i, k);
            if (k < s) continue;
            for (int i = k; !pq.empty() && (i == k || !mp.count(i)); i++) {
                auto top = pq.top(); pq.pop();
                ans += ll(i - top.second) * top.first;
            }
        }
        cout << ans << "\n";
    }
}
