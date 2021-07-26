#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

const ll LIM = 1000000;
vl vis(LIM + 1), prime, euler = {2};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (ll i = 2; i <= LIM; i++) {
		if (vis[i]) continue;
		prime.push_back(i);
		if ((i - 1) % 4LL == 0) euler.push_back(i);
		for (ll j = i; j <= LIM; j += i) vis[j] = 1;
	}

	while (1) {
		ll l, u; cin >> l >> u;
		if (l == -1 && u == -1) break;
		int cnt = upper_bound(all(prime), u) - lower_bound(all(prime), l);
		int ans = upper_bound(all(euler), u) - lower_bound(all(euler), l);
		cout << l << " " << u << " " << cnt << " " << ans << "\n";
	}
}
