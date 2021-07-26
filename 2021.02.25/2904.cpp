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

vi prime;
int vis[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 2; i <= 1e3; i++) {
		if (vis[i]) continue;
		prime.emplace_back(i);
		for (int j = i; j <= 1e3; j += i) vis[j] = 1;
	}

	map<int, int> cnt;
	auto extract = [&](int a) {
		map<int, int> curr;
		for (const auto &p : prime) {
			if (a == 1) break;
			while (a % p == 0) a /= p, cnt[p]++, curr[p]++;
		}
		if (a > 1) cnt[a]++, curr[a]++;
		return curr;
	};

	int n;
	cin >> n;
	vector<map<int, int>> vec(n);
	for (auto &i : vec) {
		int a;
		cin >> a;
		i = extract(a);
	}

	map<int, int> goal;
	ll ans = 1, mv = 0;
	for (const auto &[i, c] : cnt)
		if (c / n) goal[i] = c / n, ans *= powl(i, c / n);
	cout << ans << " ";
	for (auto &i : vec) {
		for (const auto &[j, c] : goal)
			if (c > i[j]) mv += c - i[j];
	}
	cout << mv;
}
