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

	int h, w;
	cin >> h >> w;
	vi vec(w);
	for (auto &i : vec) cin >> i;

	int ans = 0;
	auto get = [&](int s, int e) {
		if (s >= w || e >= w) return 0;
		int a = min(vec[s], vec[e]), ret = 0;
		for (int i = s; i <= e; i++) ret += max(0, a - vec[i]);
		return ret;
	};

	for (int i = 0; i < w; i++) {
		int s = i;
		for (++i; i < w; i++) {
			if (vec[s] <= vec[i]) break;
		}
		ans += get(s, i);
		if (i == w) {
			int a = max_element(vec.begin() + s + 1, vec.end()) - vec.begin();
			ans += get(s, a);
			i = a - 1;
		} else --i;
	}
	cout << ans;
}
