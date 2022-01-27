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

	vi vis(2300001), prime;
	for (int i = 2; i <= 2300000; i++) {
		if (vis[i]) continue;
		prime.push_back(i);
		for (int j = i; j <= 2300000; j += i) vis[j] = 1;
	}
	ll m1 = prime.back(); prime.pop_back();
	ll m2 = prime.back();

	prime.erase(prime.begin() + 100, prime.end());

	string a, b; cin >> a >> b;
	int n = a.size(), m = b.size();

	vector<vpii> H(m1);
	for (int i = 0; i < n; i++) {
		ll x = 1, y = 1;
		for (int j = i; j < n; j++) {
			int c = a[j] - 'a';
			x = (x * prime[c]) % m1;
			y = (y * prime[c + 26]) % m2;
			H[x].emplace_back(y, j - i + 1);
			//cout << i << " " << j << " " << x << " " << y << "\n";
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		ll x = 1, y = 1;
		for (int j = i; j < m; j++) {
			int c = b[j] - 'a';
			x = (x * prime[c]) % m1;
			y = (y * prime[c + 26]) % m2;
			//cout << i << " " << j << " " << x << " " << y << "\n";
			int len = j - i + 1;
			if (find(all(H[x]), pii(y, len)) != H[x].end())
				ans = max(ans, len);
		}
	}
	cout << ans;
}
