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

	int r, c, n; cin >> r >> c >> n;
	int _; cin >> _ >> _ >> _;
	vi xyz(3);
	for (int &i : xyz) cin >> i;
	sort(all(xyz), greater<>());
	vector<vi> vec(r, vi(c));
	for (vi &v : vec)
		for (int &i : v) cin >> i;

	auto id = [&](int i, int j) {
		return i * c + j;
	};

	vi ok(r * c);
	vpii srt;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			srt.emplace_back(vec[i][j], id(i, j));
	sort(all(srt), greater<>());

	int sum = 0;
	n -= 3;
	for (int i = 0; i < n; i++) ok[srt[i].second] = 1, sum += srt[i].first;

	auto check_adj = [&c](int i, int j) {
		int a = i / c, b = i % c;
		int x = j / c, y = j % c;

		return abs(a - x) <= 1 && abs(b - y) <= 1;
	};

	auto find_linear = [&](int &offset, vi &tmp) {
		while (ok[srt[offset].second]) offset++;
		tmp.push_back(srt[offset].second);
		ok[srt[offset].second] = 1;
		return srt[offset].first;
	};

	int ans = 0;
	for (int i = 0; i < r * c; i++) {
		for (int j = i + 1; j < r * c; j++) {
			for (int k = j + 1; k < r * c; k++) {
//				if (i == j || j == k || i == k) continue;
				int plus = 0;
				int offset = n;

				vi tmp;

				if (ok[i]) plus += find_linear(offset, tmp);
				else plus += vec[i / c][i % c], ok[i] = 1, tmp.push_back(i);

				if (ok[j]) plus += find_linear(offset, tmp);
				else plus += vec[j / c][j % c], ok[j] = 1, tmp.push_back(j);

				if (ok[k]) plus += find_linear(offset, tmp);
				else plus += vec[k / c][k % c], ok[k] = 1, tmp.push_back(k);

				int idx = 0;
				if (check_adj(i, j)) plus += xyz[idx++];
				if (check_adj(i, k)) plus += xyz[idx++];
				if (check_adj(j, k)) plus += xyz[idx++];

				for (int i : tmp) ok[i] = 0;

				ans = max(ans, sum + plus);
			}
		}
	}

	cout << ans;
}
