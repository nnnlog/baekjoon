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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, m; cin >> n >> m;
	vl vec(n), ans(n), in(n);
	for (auto &i : vec) cin >> i;
	vector<vl> out(n);
	while (m--) {
		int a, b; cin >> a >> b;
		out[a - 1].emplace_back(b - 1);
		in[b - 1]++;
	}

	queue<ll> q;
	for (int i = 0; i < n; i++)
		if (!in[i]) q.push(i), ans[i] = vec[i];

	while (!q.empty()) {
		int f = q.front(); q.pop();
		for (const auto &nxt : out[f]) {
			if (!(--in[nxt])) q.push(nxt);
			ans[nxt] = max(ans[nxt], ans[f] + vec[nxt]);
		}
	}

	cout << *max_element(all(ans));
}
