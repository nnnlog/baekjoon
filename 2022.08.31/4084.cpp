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

	while (1) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (!a) break;
        
        int ans = 0;
        while (a != b || b != c || c != d) {
            int t = a;
            a = abs(a - b);
            b = abs(b - c);
            c = abs(c - d);
            d = abs(d - t);
            
            ans++;
        }
        
        cout << ans << "\n";
    }
}
