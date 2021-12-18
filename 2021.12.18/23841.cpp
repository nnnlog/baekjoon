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
	vector<vector<char>> vec(n, vector<char>(m));
	for (auto &v : vec)
		for (auto &i : v) cin >> i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j * 2 < m; j++) {
			char a = vec[i][m / 2 - j - 1], b = vec[i][m / 2 + j];
			vec[i][m / 2 - j - 1] = vec[i][m / 2 + j] = max(a, b);
		}
	}

	for (auto &v : vec) {
		for (auto &i: v) cout << i;
		cout << "\n";
	}
}
