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
pii info[100001];
int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		UF[a] = b;
		info[b].first = min(info[a].first, info[b].first);
		info[b].second += info[a].second + 1;
		info[a] = {0, 0};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	iota(UF, UF + 100001, 0);

	int n;
	cin >> n;
	vector<pair<int, pii>> vec;
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		vec.emplace_back(c, pii(a, b));
	}
	for (int i = 1; i <= n; i++) info[i].first = 1e9;
	sort(all(vec), greater<>());
	ll ans = 0;
	for (const auto &[w, ab] : vec) {
		merge(ab.first, ab.second);
		info[find(ab.first)].first = min(info[find(ab.first)].first, w);
		ans = max(ans, (ll)info[find(ab.first)].first * info[find(ab.first)].second);
	}
	cout << ans;
}
