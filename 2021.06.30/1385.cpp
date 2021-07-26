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

vpii dxdy00 = {{0, 1}, {1, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 0}};
vpii dxdy = {{-1, 0}, {0, 1}, {1, 1}, {1, 0}, {0, -1}, {-1, -1}};
vector<vi> mp;

const int MX = 1e6 + 5 * 1e5;
int SZ;
pii A, B;
int a, b;

void init() {

	mp.assign(2 * SZ + 1, vi(2 * SZ + 1));
	queue<pii> q;
	int k;
	mp[SZ][SZ] = k = 1;
	q.emplace(0, 0);
	auto nxt = [&](int x, int y) {
		if (x + SZ < 0 || x > SZ) return;
		if (y + SZ < 0 || y > SZ) return;
		int &tmp = mp[x + SZ][y + SZ];
		if (tmp) return;
		if (k < MX) {
			tmp = ++k;
			if (tmp == a) A = {x, y};
			if (tmp == b) B = {x, y};
			q.emplace(x, y);
		}
	};
	while (!q.empty() && k < 1e6) {
		pii f = q.front();
		q.pop();
		if (f.second == 1) for (const auto &[dx, dy] : dxdy) nxt(f.first + dx, f.second + dy);
		else for (const auto &[dx, dy] : dxdy00) nxt(f.first + dx, f.second + dy);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	SZ = sqrt(MX) + 1;

	cin >> a >> b;
	init();

	queue<pii> q;
	vi vis(MX + 1);
	q.emplace(B);
	vis[b] = -1;
	auto nxt = [&](int x, int y, int o) {
		if (x + SZ < 0 || x > SZ) return;
		if (y + SZ < 0 || y > SZ) return;
		if (vis[mp[x + SZ][y + SZ]]) return;
		vis[mp[x + SZ][y + SZ]] = o;
		q.emplace(x, y);
	};
	while (!q.empty() && !vis[a]) {
		pii f = q.front();
		q.pop();
		if (f.second == 1)
			for (const auto &[dx, dy] : dxdy) nxt(f.first + dx, f.second + dy, mp[f.first + SZ][f.second + SZ]);
		else
			for (const auto &[dx, dy] : dxdy00) nxt(f.first + dx, f.second + dy, mp[f.first + SZ][f.second + SZ]);
	}
/*
	for (int i = 2; i >= -2; i--) {
		for (int j = -2; j <= 2; j++) cout << setfill(' ') << setw(2) << mp[j + SZ][i + SZ] << " ";
		cout << "\n";
	}
*/
	for (; a > 0; a = vis[a]) cout << a << " ";
}
