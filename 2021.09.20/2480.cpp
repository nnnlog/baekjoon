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

	int a, b, c; cin >> a >> b >> c;
	if (a == b && b == c) cout << 10000 + a * 1000;
	else if (a == b || a == c) cout << 1000 + a * 100;
	else if (b == c) cout << 1000 + b * 100;
	else cout << max(a, max(b, c)) * 100;
}
