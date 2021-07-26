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

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n;
		cin >> n;
		vi vec(n, -1);
		for (auto &j : vec) {
			string s;
			cin >> s;
			for (int k = n - 1; k >= 0; --k) {
				if (s[k] == '1') {
					j = k;
					break;
				}
			}
		}

		int ans = 0;
		for (int j = 0; j < n; j++) {
			int k = j;
			for (;; k++)
				if (vec[k] <= j || k == n - 1) break;
			ans += k - j;
			int t = vec[k];
			for (; k > j; --k) vec[k] = vec[k - 1];
			vec[j] = t;
		}

		cout << "Case #" << i << ": " << ans << "\n";
	}
}
