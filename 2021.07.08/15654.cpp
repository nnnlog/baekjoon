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

int fact(int a) {
	int ret = 1;
	for (int i = 2; i <= a; i++) ret *= i;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vi vec(n);
	for (auto &i : vec) cin >> i;
	sort(all(vec));
	int skip = 0;
	do {
		if (skip--) continue;
		for (int i = 0; i < m; i++) cout << vec[i] << " ";
		cout << "\n";
		skip = fact(n - m) - 1;
	} while (next_permutation(all(vec)));
}
