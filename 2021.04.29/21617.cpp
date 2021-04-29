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

	cout << fixed;
	cout.precision(15);

	int n; cin >> n;
	vi H(n + 1), W(n);
	for (auto &i : H) cin >> i;
	for (auto &i : W) cin >> i;
	ld ans = 0;
	for (int i = 0; i < n; i++) ans += W[i] * (H[i + 1] - 0.5 * (H[i + 1] - H[i]));
	cout << ans;
}
