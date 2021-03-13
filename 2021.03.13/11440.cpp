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

typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;
matrix operator * (const matrix &a, const matrix &b) {
	int n = a.size();
	matrix c(n, vector<long long>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= mod;
		}
	}
	return c;
}

ll fibo(ll n) {
	if (n <= 1) return n;

	matrix ans = {{1, 0}, {0, 1}};
	matrix a = {{1, 1}, {1, 0}};

	while (n > 0) {
		if (n % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}

	return ans[0][1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n; cin >> n;
	cout << fibo(n) * fibo(n + 1) % mod;
}
