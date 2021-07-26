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

int vis[201][201][201], a, b, c;
vi ans(201);

int mv(int &A, int &B, int lB) {
	if (!A) return 0;
	if (A + B <= lB) B += A, A = 0;
	else {
		int sum = min(lB - B, A);
		A -= sum, B += sum;
	}
	return 1;
}

void solve(int x, int y, int z) {
	int tx = x, ty = y, tz = z;
	if (mv(tx, ty, b) && !vis[tx][ty][tz]) vis[tx][ty][tz] = 1, solve(tx, ty, tz);
	if (!tx) ans[tz] = 1;
	tx = x, ty = y, tz = z;
	if (mv(tx, tz, c) && !vis[tx][ty][tz]) vis[tx][ty][tz] = 1, solve(tx, ty, tz);
	if (!tx) ans[tz] = 1;
	tx = x, ty = y, tz = z;
	if (mv(ty, tx, a) && !vis[tx][ty][tz]) vis[tx][ty][tz] = 1, solve(tx, ty, tz);
	if (!tx) ans[tz] = 1;
	tx = x, ty = y, tz = z;
	if (mv(ty, tz, c) && !vis[tx][ty][tz]) vis[tx][ty][tz] = 1, solve(tx, ty, tz);
	if (!tx) ans[tz] = 1;
	tx = x, ty = y, tz = z;
	if (mv(tz, tx, a) && !vis[tx][ty][tz]) vis[tx][ty][tz] = 1, solve(tx, ty, tz);
	if (!tx) ans[tz] = 1;
	tx = x, ty = y, tz = z;
	if (mv(tz, ty, b) && !vis[tx][ty][tz]) vis[tx][ty][tz] = 1, solve(tx, ty, tz);
	if (!tx) ans[tz] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b >> c;
	vis[0][0][c] = 1;
	ans[c] = 1;
	solve(0, 0, c);
	for (int i = 0; i <= 200; i++) if (ans[i]) cout << i << " ";
}
