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

int mp[251][251], UF[62501];
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

	int m, n; cin >> m >> n;
	auto id = [&](int a, int b) {
		return (a - 1) * n + b;
	};
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> mp[i][j];
	for (int i = 1; i <= m * n; i++) UF[i] = i;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			if (!mp[i][j]) continue;
			for (const auto &[dx, dy] : vpii{
					{-1, -1},
					{-1, 0},
					{-1, 1},
					{0, -1},
					{0, 1},
					{1, -1},
					{1, 0},
					{1, 1}
			}) {
				int a = i + dx, b = j + dy;
				if (!a || !b || a > m || b > n) continue;
				if (mp[a][b]) merge(id(a, b), id(i, j));
			}
		}
	set<int> ans;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (mp[i][j]) ans.insert(find(id(i, j)));
	cout << ans.size();
}
