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

	int n, a, b;
	cin >> n >> a >> b;

	vpii seq;
	for (int i = 1; i < 2 * n; i++) {
		int x = 0, y = i - 1;
		int dx = 1, dy = -1;
		if (i > n) {
			x = i - n;
			y = n - 1;
		}
		while (0 <= x && x < n && 0 <= y && y < n) {
			seq.emplace_back(x, y);
			x += dx;
			y += dy;
		}
	}

	vector<vi> vec(n, vi(n));
	for (const auto &[x, y] : seq) if (a-- > 0) vec[x][y] = 1;

	reverse(all(seq));
	for (const auto &[x, y] : seq) if (!vec[x][y] && (!x || vec[x - 1][y] != 1) && (!y || vec[x][y - 1] != 1) && b-- > 0) vec[x][y] = 2;

	if (a <= 0 && b <= 0) {
		cout << "1\n";
		for (auto &v: vec) {
			for (int &i: v) cout << i;
			cout << "\n";
		}
	} else cout << -1;
}
