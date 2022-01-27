#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, mx = 0, a = 1;
	cin >> n >> k;
	vector<pii> vec(k);
	for (auto &i : vec) cin >> i.first, i.second = a++, mx = max(mx, i.first);
	if (n < mx + mx - 1) {
		cout << -1;
		return 0;
	}

	sort(all(vec), greater<>());
	vi ans(n);
	int c = 0, i = 0;
	while (c * 2 < n) {
		if (!vec[i].first) ++i;
		ans[(c++) * 2] = vec[i].second;
		--vec[i].first;
	}
	for (auto &v : ans)
		if (!v) {
			if (!vec[i].first) ++i;
			v = vec[i].second;
			--vec[i].first;
		}
	for (auto &v : ans) cout << v << " ";
}
