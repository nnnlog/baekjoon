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

ll F[2'000'000], G[2'000'000];

const int MX = 19, MOD = 100003;
int SP_F[MX][MOD + 1], SP_G[MX][MOD + 1];

void update(auto &arr, int node, int start, int end, int l, int r) {
	if (start > r || end < l) return;
	if (l <= start && end <= r) ++arr[node];
	else {
		int mid = (start + end) >> 1;
		update(arr, node * 2, start, mid, l, r);
		update(arr, node * 2 + 1, mid + 1, end, l, r);
	}
}

ll query(auto &arr, int node, int start, int end, int k) {
	if (!(start <= k && k <= end)) return 0;
	if (start == end) return arr[node];
	int mid = (start + end) >> 1;
	return arr[node] + query(arr, node * 2, start, mid, k) + query(arr, node * 2 + 1, mid + 1, end, k);
}

void init(auto &arr) {
	for (int i = 1; i < MX; i++)
		for (int k = 0; k < MOD; k++)
			arr[i][k] = arr[i - 1][arr[i - 1][k]];
}

int solve(auto &arr, ll n, int x) {
	for (int i = 0; i < MX; i++)
		if (n & (1LL << i)) x = arr[i][x];
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (ull i = 0; i < MOD; i++) SP_F[0][i] = (2 * i * i - 1) % MOD, SP_G[0][i] = (4LL * i * i * i - 3 * i) % MOD;
	init(SP_F), init(SP_G);

	int n, q;
	cin >> n >> q;

	vi vec(n + 1);
	for (auto &i : vec | views::drop(1)) cin >> i;

	while (q--) {
		int t;
		cin >> t;
		if (t < 3) {
			int l, r;
			cin >> l >> r;
			if (t == 1) update(F, 1, 1, n, l, r);
			else update(G, 1, 1, n, l, r);
		} else {
			int x;
			cin >> x;
			int ans;
			ans = solve(SP_F, query(F, 1, 1, n, x), vec[x]);
			ans = solve(SP_G, query(G, 1, 1, n, x), ans);
			cout << ans << "\n";
		}
	}
}
