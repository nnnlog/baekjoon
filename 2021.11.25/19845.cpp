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

	int n, q; cin >> n >> q;

	vi vec(n);
	for (int &i : vec) cin >> i;

	auto search = [&](int i) {
		int l = 0, r = n - 1;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (vec[mid] < i) r = mid - 1;
			else l = mid;
		}
		return r;
	};

	while (q--) {
		int a, b; cin >> a >> b;
		--b;

		int right = search(a) - b + 1;
		int up = vec[b] - a;

		cout << max(0, right + up) << "\n";
	}
}
