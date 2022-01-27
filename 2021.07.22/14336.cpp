#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n, q;
		cin >> n >> q;
		vl A(n + 1), B(n + 1);
		for (int i = 1; i <= n; i++) cin >> A[i], B[i] = B[i - 1] + A[i] * (n - i + 1), A[i] += A[i - 1];
		auto get_kth_num = [&](ll k) {
			ll s = 0, e = 1e18;
			while (s < e) {
				ll mid = (s + e) >> 1;
				ll cnt = 0;
				int r = 1;
				for (int l = 1; l <= n; l++) {
					while (r <= n && A[r] - A[l - 1] <= mid) r++;
					cnt += r - l;
				}
				if (cnt < k) s = mid + 1;
				else e = mid;
			}
			return s;
		};
		auto sum = [&](ll k) {
			ll ret = 0;
			ll num = get_kth_num(k);
			int r = 1;
			for (int l = 1; l <= n; l++) {
				while (r <= n && A[r] - A[l - 1] < num) r++;
				--r;
				k -= r - l + 1;
				ret += B[r] - B[l - 1] - (n - r) * (A[r] - A[l - 1]);
			}
			return ret + num * k;
		};
		cout << "Case #" << tc << ":\n";
		while (q--) {
			ll a, b;
			cin >> a >> b;
			cout << sum(b) - sum(a - 1) << "\n";
		}
	}
}
