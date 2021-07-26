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

	int n, l, m;
	cin >> n >> l >> m;

	//vector<vi> sum(n + 1, vi(n + 1));
	unordered_map<int, unordered_map<int, int>> mp;
	vpii vec;
	while (m--) {
		int a, b;
		cin >> a >> b;
		mp[a][b] = 1;
		vec.emplace_back(a, b);
	}
	/*
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];*/

	int ans = 0;
	for (int w = 1; w < l / 2; w++) {
		int h = l / 2 - w;
		for (const auto &[i, j] : vec)
			for (int dx = -25; dx <= 0; dx++)
				for (int dy = -25; dy <= 0; dy++) {
					int cnt = 0;
					for (const auto &[a, b] : vec)
						if (i + dx <= a && a <= i + dx + w && j + dy <= b && b <= j + dy + h) ++cnt;
					ans = max(ans, cnt);
				}
	}

	cout << ans;
}
