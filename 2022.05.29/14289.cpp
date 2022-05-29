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

typedef vector<vi> matrix;
const int mod = 1e9 + 7;

matrix operator*(const matrix &a, const matrix &b) {
	matrix ret(a.size(), vi(b[0].size()));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < b.size(); k++) {
				ret[i][j] += (ll(a[i][k]) * b[k][j]) % mod;
				ret[i][j] %= mod;
			}
		}
	}

	return ret;
}

matrix pow(const matrix &base, int exp) {
	if (exp == 1) return base;
	matrix ret = pow(base, exp / 2);
	ret = ret * ret;
	if (exp % 2) ret = ret * base;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	matrix M(n, vi(n));
	while (m--) {
		int u, v;
		cin >> u >> v;

		M[--u][--v] = 1;
		M[v][u] = 1;
	}

	int d;
	cin >> d;

	cout << pow(M, d)[0][0];
}
