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

	int n, m; cin >> n >> m;
	vpii vec(n);
	for (auto &[a, b] : vec) cin >> b >> a;
	sort(all(vec), greater<>());
	vi frame(m);
	for (auto &i : frame) cin >> i;
	sort(all(frame), greater<>());
	int k = 0, ans = 0;
	for (int i = 0; i < n && k < m; i++) {
		if (vec[i].second <= frame[k]) {
			ans++;
			k++;
		}
	}
	cout << ans;
}
