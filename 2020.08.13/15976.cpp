#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
vector<pii> x, y_sum;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		x.emplace_back(a, b);
	}

	int m;
	cin >> m;
	y_sum.resize(m + 1);
	y_sum[0] = {-1, 0};
	for (int i = 1; i <= m; i++) {
		cin >> y_sum[i].first >> y_sum[i].second;
		y_sum[i].second += y_sum[i - 1].second;
	}

	ll a, b, ans = 0;
	cin >> a >> b;
	--a;
	for (const auto &p : x) {
		ans += p.second * (
				min(y_sum.begin() + m, max(y_sum.begin(), lower_bound(y_sum.begin(), y_sum.end(), pii{p.first + b, 1e9}) - 1))->second
				- max(y_sum.begin(), lower_bound(y_sum.begin(), y_sum.end(), pii{p.first + a, 1e9}) - 1)->second
		);
	}

	cout << ans;
}
