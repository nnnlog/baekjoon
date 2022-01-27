#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string n;
	cin >> n;
	int vis[10] = {0,}, g = 1;
	for (const char &c : n)
		if (!vis[c - '0'] && c - '0') {
			vis[c - '0']++;
			g = g * (c - '0') / gcd(g, c - '0');
		}

	ll i = atoll(n.c_str());
	if (i % g == 0) cout << i;
	else {
		ll add = 0;
		do {
			i *= 10;
			add++;
			ll mod = i % g ? g - (i % g) : 0;
			if (powl(10LL, add) > mod) {
				cout << i + mod;
				return 0;
			}
		} while (1);
	}
}
