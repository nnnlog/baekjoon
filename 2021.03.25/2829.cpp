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
	vector<vi> vec(n + 1, vi(n + 1)), Lsum(n + 1, vi(n + 1)), Rsum(n + 2, vi(n + 2));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> vec[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) Lsum[i][j] = Lsum[i - 1][j - 1] + vec[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = n; j >= 1; j--) Rsum[i][j] = Rsum[i - 1][j + 1] + vec[i][j];
	int ans = 0;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 2; k <= n; k++) {
				if (i + k - 1 > n || j + k - 1 > n) break;
				int a = Lsum[i + k - 1][j + k - 1] - Lsum[i - 1][j - 1];
				int b = Rsum[i + k - 1][j] - Rsum[i - 1][j + k];
				//cout << i << " " << j << " " << k << " " << a << " " << b << "\n";
				ans = max(ans, a - b);
			}
	cout << ans;
}
