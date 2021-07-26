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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int UF[250000], n, mp[500][500];

int find(int a) {
	return UF[a] = UF[a] == a ? UF[a] : find(UF[a]);
}

int merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) return UF[a] = b, 1;
	return 0;
}

inline int id(int x, int y) {
	return x * n + y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<int, vpii, greater<int>> upd;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			upd[mp[i][j]].emplace_back(i, j);
		}
	int ans = 0, curr = 0;
	for (auto it = upd.begin(); it != upd.end(); ++it) {
		int depth = it->first;
		curr += it->second.size();
		for (int i = 0; i < it->second.size(); i++) UF[id(it->second[i].first, it->second[i].second)] = id(it->second[i].first, it->second[i].second);
		for (int i = 0; i < it->second.size(); i++) {
			for (int j = 0; j < 4; j++) {
				int x = dx[j] + it->second[i].first, y = dy[j] + it->second[i].second;
				if (x < 0 || x >= n || y < 0 || y >= n) continue;
				if (mp[x][y] >= depth)
					if (merge(
							id(it->second[i].first, it->second[i].second),
							id(x, y)
					)) --curr;
			}
		}
		ans = max(ans, curr);
	}
	cout << ans;
}

