#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

vi prime;

vi solve(int n) {
	vi ret = {};
	for (const auto &a : prime) {
		if (n < a) return {};
		if (binary_search(all(prime), n - a)) return {a, n - a};
	}
	return {};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vi vis(n + 1);
	for (int i = 2; i <= n; i++) {
		if (vis[i]) continue;
		prime.push_back(i);
		for (int k = i; k <= n; k += i) vis[k] = 1;
	}
	
	if (n < 8) {
		cout << "-1";
		return 0;
	}

	int f = 0;
	vi ret = solve(n - 4);
	if (ret.size() != 2) ret = solve(n - 5), f = 1;
	if (!f) ret.push_back(2), ret.push_back(2);
	else ret.push_back(2), ret.push_back(3);

	sort(all(ret));
	for (const auto i : ret) cout << i << " ";
}
