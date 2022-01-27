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

ll ceil(ll a, ll b) {
	return a / b + (a * b > 0 && a % b != 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll L, R; cin >> L >> R;
	if (L > R) swap(L, R);
	ll x, y; cin >> x >> y;
	//if (y < 0) y += x, --x;
	if (x < 0) swap(L, R);
	ll a = (L - y) / x + ((L - y) * x > 0 && (L - y) % x != 0), b = (R - y) / x - ((R - y) * x < 0 && (R - y) % x != 0);
	//cout << L - y << " " << R - y << "\n";
	//cout << (L - y) / x << " " << (R - y) / x << "\n";
	//cout << a << " " << b << "\n";
	//assert(a <= b);
	if (a != b || y < 0 || y >= abs(x)) cout << "Unknwon Number";
	else cout << a * x + y;
}
