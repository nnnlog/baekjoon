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

inline size_t key(int i,int j) {return (size_t) i << 32 | (unsigned int) j;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vpii vec(n);
		unordered_map<size_t, bool> mp;
		for (auto &[a, b] : vec) cin >> a >> b, mp[key(a, b)] = 1;
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				pii a = vec[i], b = vec[j];
				int dx = b.second - a.second, dy = b.first - a.first;
				if (mp.count(key(a.first + dx, a.second - dy)) && mp.count(key(b.first + dx, b.second - dy)))
					ans = max(ans, dx * dx + dy * dy);
			}
		cout << ans << "\n";
	}
}
