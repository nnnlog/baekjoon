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
	
	int c = 0;
    for (int i = 0; i < 6; i++) {
        char a; cin >> a;
        c += a == 'W';
    }
    int ans = -1;
    if (c >= 1) ans = 3;
    if (c >= 3) ans = 2;
    if (c >= 5) ans = 1;
    cout << ans;
}