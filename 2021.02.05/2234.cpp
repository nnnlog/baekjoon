#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

struct A {
	int left, right, up, down;
};

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

A mp[51][51];

int UF[2551], cnt[2551], n, m;
int safe(int x, int y) {
	return x && y && x <= m && y <= n;
}
int get_id(int x, int y) {
	if (!safe(x, y)) return 0;
	return (x - 1) * n + y;
}
int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}
void merge(int a, int b) {
	if (!a || !b) return;
	a = find(a), b = find(b);
	if (a != b) UF[a] = b, cnt[b] += cnt[a], cnt[a] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) UF[i] = i, cnt[i] = 1;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			int a; cin >> a;
			//A &k = mp[i][j];
			if (!(a & 1)) merge(get_id(i, j), get_id(i, j - 1)); //left
			if (!(a & 2)) merge(get_id(i, j), get_id(i - 1, j)); //up
			if (!(a & 4)) merge(get_id(i, j), get_id(i, j + 1)); //right
			if (!(a & 8)) merge(get_id(i, j), get_id(i + 1, j)); //down
		}

	set<int> s;
	int width = 0;
	for (int i = 1; i <= m * n; i++) s.insert(find(i)), width = max(cnt[find(i)], width);
	cout << s.size() << "\n" << width << "\n";
	int ans = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			int a = find(get_id(i, j));
			for (const auto &[dx, dy] : vpii{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}) {
				int x = i + dx, y = j + dy;
				int b = find(get_id(x, y));
				if (a && b && a != b) ans = max(ans, cnt[a] + cnt[b]);
			}
		}

	cout << ans;
}
