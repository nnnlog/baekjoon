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

	ll a, x, b, y; cin >> a >> x >> b >> y;
	ll p, s; cin >> p >> s;
	if (x == 1 || (b % x && b % x <= p)) b += s;
	ll l = b / x + (b % x > 0) - 1;
	ll r = a / y + (a % y > 0);
	//cout << l << " " << r << "\n";
	cout << (l < r ? "Victory!" : "gg");
}
