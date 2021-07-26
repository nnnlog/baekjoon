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

vi UF;
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

	int n; cin >> n;
	vpii A(n), B(n), C(n);
	for (int i = 0; i < n; i++) cin >> A[i].first >> B[i].first >> C[i].first, A[i].second = i, B[i].second = i, C[i].second = i;
	sort(all(A)), sort(all(B)), sort(all(C));

	UF.resize(n);
	iota(all(UF), 0);

	vector<pair<int, pii>> edges;
	for (int i = 1; i < n; i++)
		edges.emplace_back(abs(A[i].first - A[i - 1].first), pii{A[i].second, A[i - 1].second}),
		edges.emplace_back(abs(B[i].first - B[i - 1].first), pii{B[i].second, B[i - 1].second}),
		edges.emplace_back(abs(C[i].first - C[i - 1].first), pii{C[i].second, C[i - 1].second});
	sort(all(edges));
	ll ans = 0;
	for (const auto &[w, ab] : edges)
		if (merge(ab.first, ab.second)) ans += w;
	cout << ans;
}
