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

vi UF(1000000);

int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}

int merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) return UF[a] = b, 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	iota(all(UF), 0);
	int n, m;
	cin >> n >> m;
	vector<vi> vec(n, vi(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int r, g, b;
			cin >> r >> g >> b;
			vec[i][j] = (r + g + b) / 3;
		}
	auto id = [&](int i, int j) {
		return i * m + j;
	};
	int t;
	cin >> t;
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int a = 0;
			if (vec[i][j] >= t) a = 1;
			vec[i][j] = a;
			if (a) ++ans;
			if (i && vec[i - 1][j] && a && merge(id(i, j), id(i - 1, j))) --ans;
			if (j && vec[i][j - 1] && a && merge(id(i, j), id(i, j - 1))) --ans;
		}
	cout << ans;
}
