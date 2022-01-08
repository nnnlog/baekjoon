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

    ll N; cin >> N;
    for (ll r = 2; __int128(r) * r <= N; r++) {
        ll x = r * r;
        for (ll n = 3; __int128(x) * r <= __int128(N) * 2 * (r - 1); n++) {
            x *= r;
            if ((N * (r - 1)) % (x - 1) == 0) {
                cout << n << "\n";
                ll a = N * (r - 1) / (x - 1);
                for (int i = 1; i <= n; i++) cout << a << " ", a *= r;
                return 0;
            }
        }
    }

    cout << -1;
}
