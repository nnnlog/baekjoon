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

int n;
int mp[51][51], vis[51][51][2];

pii center(vpii vec) {
	assert(vec.size() == 3);
	sort(all(vec));
	return vec[1];
}

//0: l-r, 1: u-d
int direction(vpii vec) {
	assert(vec.size() == 3);
	sort(all(vec));
	return vec[0].first != vec[1].first;
}

int safe(int x, int y) {
	return x && x <= n && y && y <= n;
}

int valid(int x, int y) {
	if (!safe(x - 1, y) || !safe(x + 1, y) || !safe(x, y - 1) || !safe(x, y + 1)) return 0;
	int s = 0;
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++) s += mp[i][j];
	return s == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vpii B, E;

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			if (c == '1') mp[i][j] = 1;
			else if (c == 'B') B.emplace_back(i, j);
			else if (c == 'E') E.emplace_back(i, j);
		}

	pii BB = center(B), EE = center(E);
	int bb = direction(B), ee = direction(E);

	queue<pair<pii, pii>> q;

	q.push({BB, {bb, 0}});
	while (!q.empty()) {
		auto front = q.front(); q.pop();
		auto push = [&](int x, int y, int s) {
			if (!safe(x, y) || vis[x][y][s] || mp[x][y]) return;
			if (s) {
				if (!safe(x + 1, y) || !safe(x - 1, y)) return;
				if (mp[x - 1][y] || mp[x][y] || mp[x + 1][y]) return;
			} else {
				if (!safe(x, y + 1) || !safe(x, y - 1)) return;
				if (mp[x][y - 1] || mp[x][y] || mp[x][y + 1]) return;
			}
			vis[x][y][s] = 1;
			q.push({{x, y}, {s, front.second.second + 1}});
		};
		int x = front.first.first, y = front.first.second;
		if (x == EE.first && y == EE.second && front.second.first == ee) {
			cout << front.second.second;
			return 0;
		}
		push(x, y + 1, front.second.first);
		push(x, y - 1, front.second.first);
		push(x + 1, y, front.second.first);
		push(x - 1, y, front.second.first);
		if (valid(x, y)) push(x, y, !front.second.first);
	}
	cout << 0;
}
