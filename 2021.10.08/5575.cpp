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

	for (int i = 0; i < 3; i++) {
		int a, b, c, x, y, z; cin >> a >> b >> c >> x >> y >> z;
		int u = a * 3600 + b * 60 + c, v = x * 3600 + y * 60 + z;
		int ans = v - u;
		cout << (ans / 3600) << " " << ((ans % 3600) / 60) << " " << (ans % 60) << "\n";
	}
}
