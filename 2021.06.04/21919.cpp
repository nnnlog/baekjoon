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

const int lim = 1000000;
int vis[lim + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	mpii prime;
	for (int i = 2; i <= lim; i++) {
		if (!vis[i]) {
			prime[i] = 1;
			for (int j = i; j <= lim; j += i) vis[j] = 1;
		}
	}

	int n; cin >> n;
	ll ans = 1;
	while (n--) {
		int a; cin >> a;
		if (prime.count(a) && ans % a) ans *= a;
	}
	cout << (ans == 1 ? -1 : ans);
}
