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

    int n, m, k;
    cin >> n >> m >> k;

    vpii vec(n);
    for (auto &[a, b] : vec) cin >> a >> b;

    sort(all(vec), [](auto a, auto b) {
       return a.second < b.second;
    });

    ll ans = 0;
    while (k--) ans += vec.back().first, vec.pop_back();

    sort(all(vec));
    while (m--) ans += vec.back().first, vec.pop_back();

    cout << ans;
}
