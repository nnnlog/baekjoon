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

	int n; cin >> n;
	vi vec(n);
	for (auto &i : vec) cin >> i;
	vi L(n), R(n);
	L.front() = vec.front(), R.back() = vec.back();
	for (int i = 1; i < n; i++) L[i] = gcd(L[i - 1], vec[i]);
	for (int i = n - 2; i >= 0; i--) R[i] = gcd(R[i + 1], vec[i]);

	int ans = -1, k;
	for (int i = 0; i < n; i++) {
		int g;
		if (!i) g = R[1];
		else if (i == n - 1) g = L[n - 2];
		else g = gcd(L[i - 1], R[i + 1]);
		if (vec[i] % g && ans < g) ans = g, k = vec[i];
	}
	cout << ans << " ";
	if (ans > 0) cout << k;
}
