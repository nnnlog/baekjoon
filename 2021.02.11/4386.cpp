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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int UF[101];

int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}

int merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return 0;
	return UF[a] = b, 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pld> vec(n);
	vector<pair<ld, pii>> edge;
	for (auto &[a, b] : vec) cin >> a >> b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j) {
				edge.push_back(
						{sqrtl(pow(vec[i].first - vec[j].first, 2) + pow(vec[i].second - vec[j].second, 2)), {i, j}});
			}
	sort(all(edge));
	for (int i = 0; i < n; i++) UF[i] = i;
	ld ans = 0;
	for (const auto &[c, i] : edge)
		if (merge(i.first, i.second)) ans += c;
	cout.precision(15);
	cout << fixed << ans;
}
