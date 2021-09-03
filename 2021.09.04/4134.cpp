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

	const ll sz = 70000;
	vl vis(sz), prime;
	for (ll i = 2; i < sz; i++) {
		if (vis[i]) continue;
		prime.push_back(i);
		for (int j = i; j < sz; j += i) vis[j] = 1;
	}

	int T;
	cin >> T;
	while (T--) {
		ll n;
		cin >> n;
		if (n <= 2) cout << "2\n";
		else {
			for (ll i = n;; i++) {
				int f = 0;
				for (const auto &j: prime)
					if (j * j > i) break;
					else if (i % j == 0) {
						f = 1;
						break;
					}
				if (!f) {
					cout << i << "\n";
					break;
				}
			}
		}
	}
}
