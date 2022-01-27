#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m, a, tmp = 0, ans = 0; cin >> n >> m;
	vector<ll> sum(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a;
		tmp += a;
		sum[tmp %= m]++;
		if (!tmp) ans++;
	}

	for (const auto &c : sum) ans += c * (c - 1) / 2;
	cout << ans;
}
