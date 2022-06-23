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

    for (int a = 1; a <= 100; a++) {
        for (int b = 2; b * b * b <= a * a * a; b++) {
            for (int c = b + 1; b * b * b + c * c * c <= a * a * a; c++) {
                for (int d = c + 1; b * b * b + c * c * c + d * d * d <= a * a * a; d++) {
                    if (a * a * a == b * b * b + c * c * c + d * d * d)
                    cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
                }
            }
        }
    }
}
