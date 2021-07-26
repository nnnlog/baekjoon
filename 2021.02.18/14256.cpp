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

int vis[280];
vi prime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 2; i <= 279; i++) {
		if (vis[i]) continue;
		prime.emplace_back(i);
		for (int j = i; j <= 279; j += i) vis[j] = 1;
	}

	auto extract = [](int a) {
		int ret = 1;
		for (const auto &p : prime) {
			if (!a) break;
			int cnt = 0;
			while (a && a % p == 0) a /= p, ++cnt;
			if (cnt % 2) ret *= p;
		}
		if (a) ret *= a;
		return ret;
	};

	int n, m; cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += sqrt(m / extract(i));
	cout << ans;
}
