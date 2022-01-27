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

	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
	int a = min(x1, x3), b = min(y1, y3), c = max(x2, x4), d = max(y2, y4);
	cout << pow(max(c - a, d - b), 2);
}
