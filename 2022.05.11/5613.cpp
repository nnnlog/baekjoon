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
	
	ll ans = 0;
    char op = 0;
    for (int i = 1;; i++) {
        string s; cin >> s;
        if (s == "=") return cout << ans, 0;
        char c = s[0];
        if ('0' <= c && c <= '9') {
            int a = atoi(s.c_str());
            if (!op) ans = a;
            else {
                if (op == '+') ans += a;
                else if (op == '-') ans -= a;
                else if (op == '/') ans /= a;
                else ans *= a;
            }
        } else op = c;
    }
}
