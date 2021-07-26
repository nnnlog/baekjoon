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

int UF[100001];
int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) UF[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<pair<int, pii>> vec(m);
	for (auto &[a, b] : vec) cin >> b.first >> b.second >> a;
	sort(all(vec), greater<>());
	for (int i = 1; i <= n; i++) UF[i] = i;
	int x, y; cin >> x >> y;
	for (const auto &[w, a] : vec) {
		merge(a.first, a.second);
		if (find(x) == find(y)) {
			cout << w;
			return 0;
		}
	}
}
