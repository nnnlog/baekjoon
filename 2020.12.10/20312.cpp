#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vl vec(n - 1);
	for (auto &i : vec) cin >> i;

	ll ans = 0, prev = 0;
	for (int i = 0; i < n - 1; i++) {
		prev = ((prev + 1) * vec[i]) % MOD;
		ans += prev;
		ans %= MOD;
	}
	cout << ans;
}
