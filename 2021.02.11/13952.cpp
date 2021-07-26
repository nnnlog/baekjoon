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

int UF[1000001];

void init() {
	for (int i = 1; i < 1000001; i++) UF[i] = i;
}

int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) UF[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<vi> sum(n + 1, vi(n + 1)), arr(n + 1, vi(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			sum[i][j] = c == '.';
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			//cout << i << " " << j << " " << sum[i][j] << "\n";
		}

	auto sect = [&](int a, int b, int x, int y) {
		if (a < 1 || b < 1 || x > n || y > n) return -1;
		return sum[x][y] - sum[x][b - 1] - sum[a - 1][y] + sum[a - 1][b - 1];
	};
	auto id = [&](int a, int b) {
		return (a - 1) * n + b;
	};

	map<int, vpii, greater<>> mp;
	for (int a = 1; a <= n; a++)
		for (int b = 1; b <= n; b++)
			for (int i = n - !(n % 2); i >= 1; i -= 2) {
				//cout << a << " " << b << " " << i << " " << sect(a - i / 2, b - i / 2, a + i / 2, b + i / 2) << "\n";
				if (sect(a - i / 2, b - i / 2, a + i / 2, b + i / 2) == i * i) {
					mp[i].emplace_back(a, b);
					arr[a][b] = i;
					break;
				}
			}


	vi cost;
	vector<vpii> edge;
	for (const auto &[a, vec] : mp) cost.emplace_back(a), edge.emplace_back(vec);
	cost.emplace_back(0);
	edge.emplace_back();

	int q;
	cin >> q;
	vector<pii> query(q), range;
	for (auto &[a, b] : query) {
		int w, x, y, z;
		cin >> w >> x >> y >> z;
		a = id(w, x);
		b = id(y, z);
		range.emplace_back(0, cost.size() - 1);
	}

	vector<vi> mid(cost.size());
	while (1) {
		for (auto &v : mid) v.clear();
		int f = 0;
		for (int i = 0; i < q; i++)
			if (range[i].first != range[i].second) f = 1, mid[(range[i].first + range[i].second) >> 1].emplace_back(i);
		if (!f) break;
		init();
		for (int i = 0; i < cost.size(); i++) {
			for (const auto &[x, y] : edge[i]) {
				for (const auto &[dx, dy] : vpii{
						{-1, 0},
						{1,  0},
						{0,  -1},
						{0,  1}
				}) {
					int a = x + dx, b = y + dy;
					if (a < 1 || b < 1 || a > n || b > n) continue;
					if (arr[a][b] >= cost[i]) merge(id(a, b), id(x, y));
				}
			}
			for (const auto &k : mid[i])
				if (find(query[k].first) == find(query[k].second))
					range[k].second = i;
				else
					range[k].first = i + 1;
		}
	}

	for (const auto &[l, r] : range) cout << cost[(l + r) >> 1] << "\n";
}
