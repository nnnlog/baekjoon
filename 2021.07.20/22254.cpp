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

	int n, x; cin >> n >> x;
	vi vec(n);
	for (auto &i : vec) cin >> i;
	queue<int> Q;
	for (int i : vec) Q.push(i);
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		priority_queue<ll, vl, greater<>> pq;
		for (int i = 0; i < mid; i++) pq.push(0);
		auto q = Q;
		int fl = 0;
		while (!q.empty()) {
			ll f = q.front(); q.pop();
			ll t = pq.top(); pq.pop();
			t += f;
			pq.push(t);
			if (t > x) {fl = 1; break; }
		}
		if (fl) l = mid + 1;
		else r = mid;
	}
	cout << ((l + r) >> 1);
}
