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

int r, c;
char arr[21][21];
vi used('Z' + 1);

int solve(int x, int y) {
	int ret = 0;
	for (const auto &[dx, dy] : vpii{
			{-1, 0},
			{0, -1},
			{1, 0},
			{0, 1}
	}) {
		int a = x + dx, b = y + dy;
		if (a > r || b > c || a < 1 || b < 1) continue;
		char nxt = arr[a][b];
		if (used[nxt]) continue;
		used[nxt] = 1;
		//cout << a << " " << b << "\n";
		ret = max(ret, solve(a, b) + 1);
		used[nxt] = 0;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> arr[i][j];

	used[arr[1][1]] = 1;
	cout << solve(1, 1) + 1;
}
