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

    ll x, k; cin >> x >> k;
    x *= 1000, k *= 1000;
    if (7 * k <= x) cout << 7 * k;
    else if (k / 2 * 7 <= x) cout << k / 2 * 7;
    else if (k / 4 * 7 <= x) cout << k / 4 * 7;
    else cout << 0;
}
