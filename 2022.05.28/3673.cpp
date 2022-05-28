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

	int T; cin >> T;
	while (T--) {
		int d, n; cin >> d >> n;
		vi vec(n + 1);
		for (int &i : vec | views::drop(1)) cin >> i;

		map<int, int> cnt;
		vi sum(n + 1);
		for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + vec[i]) % d, cnt[sum[i]]++;

		ll ans = 0;
		for (const auto &[k, v] : cnt) {
			ans += v * ll(v - 1) / 2;
			if (k == 0) ans += v;
		}

		cout << ans << "\n";
	}
}
