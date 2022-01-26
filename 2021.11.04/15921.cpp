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

	cout.precision(2);
	cout << fixed;

	int n; cin >> n;
	mpii mp;
	ld avg = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		mp[a]++;
		avg += a;
	}

	if (n == 0) {
		cout << "divide by zero";
		return 0;
	}

	avg /= n;
	ld x = 0;
	for (const auto &[a, b] : mp) x += a * (ld(b) / n);

	ld ans = avg / x;
	ans = round(ans * 100) / 100;
	cout << ans;
}
