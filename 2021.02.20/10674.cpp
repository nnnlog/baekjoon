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

	int n, m; cin >> n >> m;
	vector<vi> A(n + 1, vi(n + 1)), B(n + 1, vi(n + 1));
	while (m--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		A[b][a] = c;
		B[b][a] = d;
	}

	vector<vi> dp_a(n + 1, vi(10001)), dp_b(n + 1, vi(10001));
	dp_a[1][0] = dp_b[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i - 1; j++) {
			if (!A[i][j]) continue;
			int a = A[i][j], b = B[i][j];
			for (int k = a; k <= 10000; k++) if (dp_a[j][k - a]) dp_a[i][k] = 1;
			for (int k = b; k <= 10000; k++) if (dp_b[j][k - b]) dp_b[i][k] = 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= 10000; i++)
		if (dp_a[n][i] == dp_b[n][i] && dp_a[n][i]) {
			ans = i;
			break;
		}
	if (!ans) cout << "IMPOSSIBLE";
	else cout << ans;
}
