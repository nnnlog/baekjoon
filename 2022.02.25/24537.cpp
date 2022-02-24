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

    vi mp(1e6 + 1);
    int n;
    cin >> n;
    int mx = 0;
    while (n--) {
        int a;
        cin >> a;
        mp[a]++;
        mx = max(mx, a);
    }

    vi G(mx + 1), cnt(mx + 1);
    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            if (!mp[j]) continue;
            G[i] = gcd(G[i], j);
            cnt[i] += mp[j];
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int a;
        cin >> a;
        if (a > mx || G[a] != a) cout << "-1\n";
        else cout << cnt[a] << "\n";
    }
}
