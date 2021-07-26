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

int vis[2237];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vi prime;
	for (int i = 2; i <= 2236; i++) {
		if (vis[i]) continue;
		prime.push_back(i);
		for (int j = i; j <= 2236; j += i) vis[j] = 1;
	}

	int n; cin >> n;
	while (n--) {
		int a; cin >> a;
		for (const auto &p : prime)
			while (a % p == 0) cout << p << " ", a /= p;
		if (a > 1) cout << a;
		cout << "\n";
	}
}
