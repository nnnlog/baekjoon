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

struct Hashing {
	ll mod;
	vl H, B;

	Hashing(ll p, ll m, const string &vec) {
		mod = m;

		H.resize(vec.size() + 1), B.resize(vec.size() + 1);
		B[0] = 1;
		for (int i = 1; i <= vec.size(); i++) {
			H[i] = (H[i - 1] * p + vec[i - 1]) % mod;
			B[i] = (B[i - 1] * p) % mod;
		}
	}

	ll substr(int l, int r) {
		ll ret = H[r] - (B[r - l + 1] * H[l - 1]) % mod;
		while (ret < 0) ret += mod;
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s; cin >> s;

	int n = s.size();

	Hashing A(917, 1'000'000'007, s);
	Hashing B(119, 1'000'000'009, s);

	auto substr = [&A, &B](int l, int r) {
		return pii(A.substr(l, r), B.substr(l, r));
	};

	int m; cin >> m;
	while (m--) {
		int a; cin >> a;
		int l = 0, r = a;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (substr(a - mid + 1, a) == substr(n - mid + 1, n)) l = mid;
			else r = mid - 1;
		}
		cout << r << "\n";
	}
}
