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

vi UF(1001);
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

	int n, m; cin >> n >> m;
	vpii vec(n);
	for (auto &[a, b] : vec) cin >> a >> b;
	vector<pair<ld, pii>> graph;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			graph.emplace_back(sqrtl(pow(vec[i].first - vec[j].first, 2) + pow(vec[i].second - vec[j].second, 2)), pii(i + 1, j + 1));
	iota(all(UF), 0);
	while (m--) {
		int a, b; cin >> a >> b;
		merge(a, b);
	}
	sort(all(graph));
	ld ans = 0;
	for (const auto &[w, uv] : graph)
		if (merge(uv.first, uv.second)) ans += w;
	cout << setprecision(2) << fixed << ans;
}
