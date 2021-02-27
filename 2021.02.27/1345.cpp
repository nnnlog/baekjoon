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

	cout.precision(15);
	cout << fixed;

	ld n, a; cin >> n >> a;
	vl vec(n);
	for (auto &i : vec) cin >> i;

	/**
	 * 공차 d를 기준으로 새로운 수열을 생성합니다.
	 * 새로운 수열이 입력된 수열 S보다 작으면 -1, 크면 1을 반환하며,
	 * 완전히 같은 경우 0을 반환합니다.
	 */
	auto chk = [&](ld d) {
		ld curr = a;
		//cout << "start " << d << "\n";
		for (int i = 0; i < n; i++) {
			curr += d;
			//cout << curr << "\n";
			if (vec[i] != (ll)floor(curr + 1e-17)) {
				return vec[i] < (ll)curr ? 1 : -1;
			}
		}
		return 0;
	};

	ld l = 0, r = 1e8, mid;
	for (int i = 0; i < 1000; i++) {
		mid = (l + r) / 2.0;
		int ret = chk(mid);
		//cout << l << " " << r << " " << mid << " -> " << chk(mid) << "\n";
		if (ret == -1) l = mid + 1e-15;
		else if (ret == 1) r = mid - 1e-15;
		else r = mid;
	}

	mid = (l + r) / 2.0;
	if (!chk(mid) && mid >= 0) cout << mid;
	else cout << "-1";
}
