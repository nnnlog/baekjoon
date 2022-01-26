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
	
	string s; cin >> s;
    if (s.size() == 2) {
        cout << s[0] + s[1] - 2 * '0';
        return 0;
    }
    if (s.size() == 4) {
        cout << 20;
        return 0;
    }
    int a, b;
    if (s[1] == '0') a = 10, b = s[2] - '0';
    else a = s[0] - '0', b = 10;
    cout << a + b;
}
