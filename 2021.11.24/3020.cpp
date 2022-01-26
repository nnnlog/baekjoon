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

	int n, h; cin >> n >> h;

	vi sa(h + 1), sb(h + 1);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (i % 2) sb[h]++, sb[h - x]--;
		else sa[1]++, sa[x + 1]--;
	}

	vi res(h + 1);
	int s = 0;
	for (int i = 1; i <= h; i++) {
		s += sa[i];
		res[i] += s;
	}
	s = 0;
	for (int i = h; i >= 1; i--) {
		s += sb[i];
		res[i] += s;
	}

	int ans = *min_element(res.begin() + 1, res.end());
	int cnt = 0;
	for (int i : res | views::drop(1)) if (i == ans) cnt++;
	cout << ans << " " << cnt;
}
