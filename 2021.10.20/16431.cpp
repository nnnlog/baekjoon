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

	int a, b, c, d, x, y; cin >> a >> b >> c >> d >> x >> y;
	int d1 = min(abs(a - x), abs(b - y));
	d1 += abs(a - x) + abs(b - y) - d1 * 2;
	int d2 = abs(c - x) + abs(d - y);
	if (d1 == d2) cout << "tie";
	else cout << (d1 < d2 ? "bessie" : "daisy");
}
