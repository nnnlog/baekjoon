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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vl vec(n + 1), sum(n + 1), par(n + 1), has_child(n + 1);
	for (int i = 2; i <= n; i++) {
		char c; cin >> c;
		int a, b; cin >> a >> b;
		if (c == 'S') sum[i] = a;
		else vec[i] = a;
		par[i] = b;
		++has_child[b];
	}
	queue<ll> q;
	for (int i = 2; i <= n; i++) if (!has_child[i]) q.push(i);
	while (!q.empty()) {
		auto f = q.front(); q.pop();
		ll cnt = sum[f];
		ll p = par[f];
		if (!vec[p]) sum[p] += cnt;
		else {
			vec[p] -= cnt;
			if (vec[p] < 0) sum[p] -= vec[p], vec[p] = 0;
		}
		if (p > 1 && !--has_child[p]) q.push(p);
	}
	cout << sum[1];
}
