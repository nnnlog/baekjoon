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

	int h, w, n;
	cin >> h >> w >> n;
	vector<vi> vec(h + 1, vi(w + 1)), dp(h + 1, vi(w + 1));
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> vec[i][j];
	dp[0][0] = n - 1;
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
		int k = dp[i][j];
		dp[i + 1][j] += k / 2 + (k % 2 && !vec[i][j]);
		dp[i][j + 1] += k / 2 + (k % 2 && vec[i][j]);
	}
	int x = 0, y = 0;
	while (x < h && y < w) {
		if (!((dp[x][y] % 2) ^ vec[x][y])) ++x;
		else ++y;
	}
	cout << x + 1 << " " << y + 1;
}
