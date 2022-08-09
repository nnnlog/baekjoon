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

	cout << fixed;
	cout.precision(3);
	
    for (int i = 1;; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (!a && !b && !c) break;
        cout << "Triangle #" << i << "\n";
        if (c == -1) {
            ld k = sqrt(a * a + b * b);
            if (a + b > k) cout << "c = " << k << "\n";
            else cout << "Impossible.\n";
        } else if (b == -1) {
            ld k = sqrt(c * c - a * a);
            if (a + k > c) cout << "b = " << k << "\n";
            else cout << "Impossible.\n";
        } else if (a == -1) {
            ld k = sqrt(c * c - b * b);
            if (k + b > c) cout << "a = " << k << "\n";
            else cout << "Impossible.\n";
        }
        cout << "\n";
    }
}
