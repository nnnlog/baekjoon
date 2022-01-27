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

	string s;
	ll n;
	cin >> s >> n;

	int idx = s.size() - 1;
	ll sz = s.size();
	while (n) {
		if (n <= s.size()) {
			cout << s[n - 1];
			return 0;
		}
		sz *= 2;
		if (n < sz) {
			sz /= 2;
			n -= sz;

			if (n <= 1) {
				cout << s[idx];
				return 0;
			}
			--n;
			sz = s.size();
			idx = s.size();
		}
		--idx;
		if (idx < 0) idx = s.size() - 1;
	}
}
