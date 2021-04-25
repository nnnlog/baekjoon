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
	vector<char> vec(n);
	for (auto &i : vec) cin >> i;
	int l = 0, r = n - 1;
	string ans;
	while (l <= r) {
		//cout << l << " " << r << "\n";
		if (vec[l] != vec[r]) {
			if (vec[l] < vec[r]) ans.push_back(vec[l]), ++l;
			else ans.push_back(vec[r]), --r;
		} else {
			for (int i = 1; l + i < r - i; i++) {
				int x = l + i, y = r - i;
				if (vec[x] != vec[y]) {
					if (vec[x] < vec[y]) ans.push_back(vec[l++]);
					else ans.push_back(vec[r--]);
					goto nxt;
				}
				//cout << x << " " << y << "\n";
			}
			ans.push_back(vec[l++]);
			nxt:;
		}
	}
	assert(ans.size() == vec.size());
	assert(r == l - 1);
	for (int i = 1; i <= ans.size(); i++) {
		cout << ans[i - 1];
		if (i % 80 == 0) cout << "\n";
	}
}
