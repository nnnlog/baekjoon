#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

const int lim = (int)(1e5);
vi prime;
int vis[lim + 1];

mpii extract(ull a) {
	mpii ret;
	for (const auto &p : prime) {
		if (a <= 1) break;
		while (a % p == 0) ret[p]++, a /= p;
	}
	if (a > 1) ret[a] = 1;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 2; i <= lim; i++) {
		if (vis[i]) continue;
		prime.push_back(i);
		for (int j = i; j <= lim; j += i) vis[j] = 1;
	}

	int a, b;
	cin >> a >> b;
	ull g = 0, l = 1;
	mpii el;
	while (a--) {
		int c;
		cin >> c;
		if (!c) {
			l = 0;
			break;
		}
		for (const auto &[a, b] : extract(c))
			el[a] = max(el[a], b);
	}

	while (b--) {
		int c;
		cin >> c;
		if (!c) {
			g = 0;
			break;
		}
		if (!g) g = c;
		else g = gcd(g, c);
	}
	//cout << l << " " << g << "\n";
	auto eg = extract(g);
	ll ans = 1, f = !g || !l;
	for (const auto &[a, b] : el) eg[a] -= b;
	for (const auto &[a, b] : eg)
		if (b < 0) f = 1;
		else ans *= b + 1;

	cout << (f ? 0 : ans);
}
