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
	
	int a, b, c, d; cin >> a >> b >> c >> d;
    int s = a + b + c + d;
    int ans = 1e9;
    ans = min(ans, abs(a + b - c - d));
    ans = min(ans, abs(a + c - b - d));
    ans = min(ans, abs(a + d - b - c));
    ans = min(ans, abs(b + c - a - d));
    ans = min(ans, abs(b + d - a - c));
    ans = min(ans, abs(c + d - a - b));
    cout << ans;
}
