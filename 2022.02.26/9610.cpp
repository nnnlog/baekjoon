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
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    while (n--) {
        int x, y; cin >> x >> y;
        if (!x || !y) e++;
        else if (x > 0 && y > 0) a++;
        else if (x > 0 && y < 0) d++;
        else if (x < 0 && y < 0) c++;
        else b++;
    }
    cout << "Q1: " << a << "\n";
    cout << "Q2: " << b << "\n";
    cout << "Q3: " << c << "\n";
    cout << "Q4: " << d << "\n";
    cout << "AXIS: " << e << "\n";
}
