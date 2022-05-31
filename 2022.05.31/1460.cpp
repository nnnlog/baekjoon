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

	int n, m;
	cin >> n >> m;

	vector<vi> vec(n + 1, vi(n + 1));
	while (m--) {
		int x, y, l, f;
		cin >> x >> y >> l >> f;

		++x, ++y;

		for (int i = x; i < x + l; i++)
			for (int j = y; j < y + l; j++)
				vec[i][j] = f;
	}

	vector<vector<vi>> sum(8, vector<vi>(n + 1, vi(n + 1)));
	for (int x = 0; x <= 7; x++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sum[x][i][j] = sum[x][i - 1][j] + sum[x][i][j - 1] - sum[x][i - 1][j - 1] + (vec[i][j] == x);
			}
		}
	}

	auto get_sum = [&](int color, int a, int b, int c, int d) {
		auto &v = sum[color];
		return v[c][d] - v[c][b - 1] - v[a - 1][d] + v[a - 1][b - 1];
	};

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!vec[i][j]) continue;
			
			int l = 1, r = n;
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				int a = i, b = j, c = i + mid - 1, d = j + mid - 1;
				if (c > n || d > n) {
					r = mid - 1;
					continue;
				}
				if (get_sum(0, a, b, c, d)) {
					r = mid - 1;
					continue;
				}

				int cnt = 0;
				for (int k = 1; k <= 7; k++) cnt += get_sum(k, a, b, c, d) > 0;

				if (cnt <= 2) l = mid;
				else r = mid - 1;
			}

			assert(l == r);
			ans = max(ans, r * r);
		}
	}

	cout << ans;
}
