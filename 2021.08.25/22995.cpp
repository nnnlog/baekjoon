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

	int T; cin >> T;
	while (T--) {
		int k; cin >> k;
		vi ans;
		for (int i = 1; (1 << i) - 1 <= k; i++) ans.push_back(i);
		k -= 1 << ans.size();
		++k;
		for (int i = ans.size() - 1; i >= 0; --i)
			if (k >= (1 << i)) {
				k -= 1 << i;
				ans.push_back(ans[i]);
			}
		assert(k == 0);
		cout << ans.size() << "\n";
		for (int i : ans) cout << i << " ";
		cout << "\n";
	}
}
