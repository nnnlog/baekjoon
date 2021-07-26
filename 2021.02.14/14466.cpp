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

int mp[101][101][101][101], UF[10001];

int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) UF[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, r;
	cin >> n >> k >> r;
	for (int i = 0; i < r; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		mp[a][b][c][d] = 1;
		mp[c][d][a][b] = 1;
	}
	vpii vec(k);
	for (auto &[a, b] : vec) cin >> a >> b;
	auto id = [&](int a, int b) {
		return (a - 1) * n + b;
	};
	for (int i = 1; i <= 10000; i++) UF[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			for (const auto &[dx, dy] : vpii{
					{-1, 0},
					{0,  -1},
					{0,  1},
					{1,  0},
			}) {
				int x = dx + i, y = dy + j;
				if (!x || x > n || !y || y > n) continue;
				if (mp[i][j][x][y]) continue;
				merge(id(i, j), id(x, y));
			}
		}

	int ans = 0;
	for (int i = 0; i < k; i++)
		for (int j = i + 1; j < k; j++)
			if (find(id(vec[i].first, vec[i].second)) != find(id(vec[j].first, vec[j].second))) ++ans;
	cout << ans;
}
