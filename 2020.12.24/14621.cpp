#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int UF[1001];
int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}
int merge(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		UF[x] = y;
		return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<char> school(n + 1);
	vector<pair<int, pii>> edge;
	for (int i = 1; i <= n; i++) cin >> school[i];
	while (m--) {
		int u, v, d; cin >> u >> v >> d;
		if (school[u] == school[v]) continue;
		edge.emplace_back(d, pii(u, v));
	}

	for (int i = 0; i <= 1000; i++) UF[i] = i;

	int ans = 0;
	sort(all(edge));
	for (const auto &[d, where] : edge) {
		int x = where.first, y = where.second;
		if (merge(x, y)) {
			ans += d;
		}
	}
	
	int f = 0;
	for (int i = 1; i <= n; i++)
		if (find(i) != find(1)) f = 1;
	
	cout << (!f ? ans : -1);
}
