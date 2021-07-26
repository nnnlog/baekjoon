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

int UF[100001], cnt[100001];

int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}

int merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return 0;
	cnt[b] += cnt[a];
	cnt[a] = 0;
	return UF[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<pair<int, pii>> edge;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.emplace_back(c, pii(a, b));
	}
	sort(all(edge));
	for (int i = 1; i <= n; i++) UF[i] = i, cnt[i] = 1;
	ll ans = 0;
	int last = 0;
	for (const auto &[c, pi] : edge) {
		if (merge(pi.first, pi.second)) ans += c, last = c;
	}
	cout << ans - last;
}
