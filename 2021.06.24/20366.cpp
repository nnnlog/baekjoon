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

	int n; cin >> n;
	vi vec(n);
	for (auto &i : vec) cin >> i;
	sort(all(vec));
	vec.push_back(1e9);
	int ans = 2 * 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int s = vec[i] + vec[j];
			auto nxt = [&](int k) {
				do {
					++k;
				} while (i == k || j == k);
				return k;
			};
			auto prv = [&](int k) {
				do {
					--k;
				} while (i == k || j == k);
				return k;
			};
			int l = nxt(-1);
			int r = prv(n);
			if (l >= r) continue;
			int sum = vec[l] + vec[r];
			while (l < r) {
				ans = min(ans, abs(sum - s));
				if (sum < s) {
					sum -= vec[l];
					l = nxt(l);
					if (l >= r) break;
					sum += vec[l];
				} else {
					sum -= vec[r];
					r = prv(r);
					if (l >= r) break;
					sum += vec[r];
				}
			}
		}
	}
	cout << ans;
}
