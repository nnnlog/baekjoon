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

int valid(char c, int base) {
	if (base <= 10) return '0' <= c && c <= base + '0' - 1;
	return ('0' <= c && c <= '9') || (base > 10 && 'a' <= c && c <= 'a' + base - 11);
}

int conv(char c) {
	if ('0' <= c && c <= '9') return c - '0';
	return c - 'a' + 10;
}

ll get(string A, int base) {
	__int128 calc = 0;
	reverse(all(A));
	for (__int128 i = 0; i < A.size(); i++) {
		if (!valid(A[i], base)) return -1;
		__int128 m = 1;
		for (int j = 0; j < i; j++) {
			m *= base;
			if (m >= LLONG_MAX) return -1;
		}
		calc += conv(A[i]) * m;
		if (calc >= LLONG_MAX) return -1;
	}
	return (ll)(calc);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string A, B;
	cin >> A >> B;
	string ans = "Impossible";
	for (int i = 2; i <= 36; i++) {
		for (int j = 2; j <= 36; j++) {
			if (i == j) continue;
			ll x = get(A, i), y = get(B, j);
			//cout << i << " " << j << " " << x << " " << y << "\n";
			if (x < 0 || y < 0 || x != y) continue;
			if (ans != "Impossible") {
				cout << "Multiple";
				return 0;
			}
			ans = to_string(x) + " " + to_string(i) + " " + to_string(j);
		}
	}

	cout << ans;
}
