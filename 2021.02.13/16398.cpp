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

int UF[1000];
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

	ll n, c, ans = 0; cin >> n;
	vector<pair<int, pii>> edge;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> c, edge.emplace_back(c, pii(i, j));
	sort(all(edge));
	for (int i = 0; i < n; i++) UF[i] = i;
	for (const auto &[c, u] : edge)
		if (merge(u.first, u.second)) ans += c;
	cout << ans;
}
