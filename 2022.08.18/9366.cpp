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
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        ll a, b, c;
        vi vec(3);
        for (int &i : vec) cin >> i;
        sort(all(vec));
        a = vec[0];
        b = vec[1];
        c = vec[2];
        if (a + b <= c) cout << "invalid!\n";
        else if (a == b && b == c) cout << "equilateral\n";
        else if (a == b || b == c) cout << "isosceles\n";
        else cout << "scalene\n";
    }
}
