#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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
	vl vec(n + 1);
	for (auto &i : vec | drop(1)) cin >> i, assert(i <= 1e9);

	int ans = 1e9;
	{
		int cnt = 0, k = 0;
		for (int i = 2; i <= n; i++) {
			if (vec[i - 1] > vec[i]) {
				++cnt;
				if (cnt > 1) break;
				k = i - 1;
			}
		}
		if (!cnt) ans = 0;
		if (cnt == 1 && vec.back() <= vec[1]) ans = min(ans, k);
	}

	{
		int cnt = 0, k = 0;
		for (int i = 2; i <= n; i++) {
			if (vec[i - 1] < vec[i]) {
				++cnt;
				if (cnt > 1) break;
				k = i - 1;
			}
		}
		if (!cnt) ans = 0;
		if (cnt == 1 && vec.back() >= vec[1]) ans = min(ans, k);
	}

	cout << (ans == 1e9 ? -1 : ans);
}
