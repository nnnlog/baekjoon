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

long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long a = x1 * y2 + x2 * y3 + x3 * y1;
	long long b = y1 * x2 + y2 * x3 + y3 * x1;
	return a < b ? 1 : -1;
}

int main() {

	int x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	ll abc = CCW(x1, y1, x2, y2, x3, y3);
	ll abd = CCW(x1, y1, x2, y2, x4, y4);
	ll cda = CCW(x3, y3, x4, y4, x1, y1);
	ll cdb = CCW(x3, y3, x4, y4, x2, y2);

	cout << (abc * abd <= 0 && cda * cdb <= 0);
}
