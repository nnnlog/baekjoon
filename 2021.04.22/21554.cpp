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

	int n;
	cin >> n;
	vpii ans;
	vi vec(n + 1);
	for (int i = 1; i <= n; i++) cin >> vec[i];
	for (int j = 1; j <= 101; j++) {
		int f = 0;
		for (int i = 1; i <= n; i++)
			if (vec[i] != i) {
				f = 1;
				break;
			}
		if (!f) break;
		if (j > 100) {
			cout << "-1";
			return 0;
		}
		int st = 0;
		for (int i = 1; i <= n; i++)
			if (vec[i] != i) {
				st = i;
				break;
			}
		for (int i = 1; i <= n; i++)
			if (vec[i] == st) {
				ans.emplace_back(st, i);
				reverse(vec.begin() + st, vec.begin() + i + 1);
			}
	}

	cout << ans.size() << "\n";
	for (const auto &a : ans) cout << a.first << " " << a.second << "\n";
}
