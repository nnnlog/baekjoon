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

int UF[100001];
int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
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
	vector<pair<int, pii>> vec;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		vec.push_back({c, {a, b}});
	}
	iota(UF, UF + n + 1, 0);
	sort(all(vec));
	ll ans = 0;
	for (auto &[a, bc] : vec) {
		if (!merge(bc.first, bc.second)) ans += a;
	}
	for (int i = 1; i <= n; i++) if (find(i) != find(1)) ans = -1;
	cout << ans;
}
