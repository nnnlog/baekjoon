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

    int n; cin >> n;
    vi cost(n);
    for (int &i : cost) cin >> i;
    vector<vpii> sale(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        while (x--) {
            int a, b; cin >> a >> b;
            sale[i].emplace_back(a, b);
        }
    }

    vi vec(n);
    iota(all(vec), 0);
    int ans = 1e9;
    do {
        int cnt = 0;
        vi minus(n);
        for (int i : vec) {
            cnt += max(1, cost[i] - minus[i]);
            for (const auto &[a, b] : sale[i]) minus[a - 1] += b;
        }
        ans = min(ans, cnt);
    } while (next_permutation(all(vec)));
    cout << ans;
}