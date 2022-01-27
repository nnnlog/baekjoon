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
	vector<vector<char>> vec(n, vector<char>(n));
	unordered_map<char, vpii> mp;
	pii s, e;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			auto &k = vec[i][j];
			cin >> k;
			if (k == 'H') s = {i, j}, k = 'X';
			if (k == '#') e = {i, j}, k = 'X';
			if (k == 'J') k = 'A';
			if (k == 'C') k = 'H';
			if (k == 'B') k = 'M';
			if (k == 'W') k = 'T';

			if (k != 'X') mp[k].emplace_back(i, j);
		}
	auto dist = [](pii x, pii y) {
		return abs(x.first - y.first) + abs(x.second - y.second);
	};
	pair<int, char> ans = {1e9, '_'};
	for (auto &[c, v] : mp) {
		sort(all(v));
		do {
			ans = min(ans, {dist(s, v[0]) + dist(v[0], v[1]) + dist(v[1], v[2]) + dist(v[2], e), c});
		} while (next_permutation(all(v)));
	}
	cout << unordered_map<char, string>{
		{'A', "Assassin"},
		{'H', "Healer"},
		{'M', "Mage"},
		{'T', "Tanker"},
	}[ans.second];
}
