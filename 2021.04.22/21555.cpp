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

	ll n, k, ans = 0; cin >> n >> k;

	vl A(n), B(n);
	for (auto &i : A) cin >> i;
	for (auto &i : B) cin >> i;

	vl dp_a(n), dp_b(n);
	dp_a[0] = A[0];
	dp_b[0] = B[0];
	for (int i = 1; i < n; i++) {
		dp_a[i] = min(dp_a[i - 1] + A[i], dp_b[i - 1] + k + A[i]);
		dp_b[i] = min(dp_b[i - 1] + B[i], dp_a[i - 1] + k + B[i]);
	}
	cout << min(dp_a.back(), dp_b.back());
}
