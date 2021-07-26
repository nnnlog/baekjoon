#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 1;
	cin >> T;
	while (T--) {
		ld n;
		cin >> n;
		ld lim = (-1 + sqrt(8 * n + 1)) / 2;
		int ans = 0;
		for (ld k = 2; k <= lim; k++) {
			ld a = -(k / 2) + 0.5 + (n / k);
			if (a == (ll)a) ans++;
		}
		cout << ans << "\n";
	}
}
