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
	vi vec(n + 1);
	for (int &i : vec | views::drop(1)) cin >> i;
	set<pii> S;
	for (int i = 1; i <= 2 * m - 1; i++) S.insert({vec[i], i});
	for (int i = m; i <= n - m + 1; i++) {
		cout << S.rbegin()->first << " ";
		S.erase({vec[i - m + 1], i - m + 1});
		if (i + m <= n) S.insert({vec[i + m], i + m});
	}
}
