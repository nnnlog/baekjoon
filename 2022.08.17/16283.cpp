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

	int a, b, n, w; cin >> a >> b >> n >> w;
    if (a == b) {
    	if (n == 2 && a + b == w) cout << "1 1"; 
    	else cout << -1;
    } else if ((w - b * n) % (a - b)) cout << -1;
    else {
        int k = (w - b * n) / (a - b);
        if (k <= 0 || k >= n) cout << -1;
        else cout << k << " " << n - k;
    }
}
