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

	int k, T; cin >> k >> T;
	while (T--) {
		int x, y; cin >> x >> y;
		if (x == y) cout << "1\n";
		else if (x < y) cout << (k + x - 2 * (y - 1) > 0) << "\n";
		else cout << (k - 2 * (x - 1) + y + 1 > 0) << "\n";
	}
}
