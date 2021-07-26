#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int UF[100000];
int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) UF[a] = b;
}

vector<vi> vec;
vpii edges, range;
vector<vi> mid;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	vec.resize(m);
	mid.resize(q);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		vec[a - 1].push_back(i);
	}

	for (int i = 0; i < m; i++)
		if (vec[i].size() > 1) range.emplace_back(0, q);
		else range.emplace_back(0, -2);

	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		edges.emplace_back(a - 1, b - 1);
	}

	while (1) {
		for (auto &v : mid) v.clear();
		int f = 0;
		for (int i = 0; i < m; i++) {
			if (range[i].first >= range[i].second) continue;
			f = 1;
			mid[(range[i].first + range[i].second) >> 1].push_back(i);
		}
		if (!f) break;
		for (int i = 0; i < 100000; i++) UF[i] = i;
		for (int i = 0; i < q; i++) {
			merge(edges[i].first, edges[i].second);
			for (const auto &j : mid[i]) {
				f = 0;
				if (!vec[j].empty()) {
					for (const auto &k : vec[j]) {
						if (find(k) != find(vec[j].back())) {
							f = 1;
							break;
						}
					}
				}
				if (!f) range[j].second = i;
				else range[j].first = i + 1;
			}
		}
	}

	for (const auto &[a, b] : range) {
		int ans = (a + b) >> 1;
		cout << (ans >= q ? -1 : ans + 1) << "\n";
	}
}
