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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int p, m, n;
    cin >> p >> m >> n;

    vi diff(2000);
    for (int i = 0; i < 1000; i += a + b) diff[i]++, diff[i + a]--;
    for (int i = 0; i < 1000; i += c + d) diff[i]++, diff[i + c]--;

    assert(a <= 999);
    assert(b <= 999);
    assert(c <= 999);
    assert(d <= 999);
    assert(p <= 999);
    assert(m <= 999);
    assert(n <= 999);

    int x, y, z;

    int s = 0;
    for (int i = 0; i < 1000; i++) {
        if (i == p) x = s;
        if (i == m) y = s;
        if (i == n) z = s;
        s += diff[i];
    }

    cout << x << "\n" << y << "\n" << z;
}
