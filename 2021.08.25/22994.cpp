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

	int n, m;
	cin >> n >> m;
	vector<string> vec(n);
	for (auto &s : vec) cin >> s;
	int i = n;
	for (; i >= 1; --i) {
		if (n % i) continue;
		int fail = 0;
		for (int y = 0; y < m && !fail; y++) {
			vi chk(n / i);
			for (int x = 0; x < n && !fail; x++) {
				if (x % i == 0) chk[x / i] = vec[x][y];
				else if (chk[x / i] != vec[x][y]) fail = 1;
			}
		}
		if (!fail) break;
	}

	int j = m;
	for (; j >= 1; --j) {
		if (m % j) continue;
		int fail = 0;
		for (int x = 0; x < n && !fail; x++) {
			vi chk(m / j);
			for (int y = 0; y < m && !fail; y++) {
				if (y % j == 0) chk[y / j] = vec[x][y];
				else if (chk[y / j] != vec[x][y]) fail = 1;
			}
		}
		if (!fail) break;
	}

	cout << n / i << " " << m / j << "\n";
	for (int x = 0; x < n; x += i) {
		for (int y = 0; y < m; y += j) cout << vec[x][y];
		cout << "\n";
	}
}
