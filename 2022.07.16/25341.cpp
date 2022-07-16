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

    int n, m, q;
    cin >> n >> m >> q;

    vl weight(m + 1);
    vector<vpii> cnt(m + 1);
    vi bias(m + 1);
    for (int i = 1; i <= m; i++) {
        int a; cin >> a;
        cnt[i].resize(a);
        for (auto &[x, y] : cnt[i]) cin >> x;
        for (auto &[x, y] : cnt[i]) cin >> y;
        cin >> bias[i];
    }

    vl final(n + 1);
    ll final_bias = 0;
    {
        for (int i = 1; i <= m; i++) {
            int a; cin >> a;
            for (const auto &[x, y] : cnt[i]) final[x] += a * y;
            final_bias += a * bias[i];
        }
        int a; cin >> a;
        final_bias += a;
    }

    while (q--) {
        ll ans = final_bias;
        for (int i = 1; i <= n; i++) {
            ll a; cin >> a;
            ans += final[i] * a;
        }
        cout << ans << "\n";
    }
}
