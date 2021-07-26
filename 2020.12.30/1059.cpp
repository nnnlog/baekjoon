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

	int sz; cin >> sz;
	vi vec(sz);
	for (auto &i : vec) cin >> i;
	vec.push_back(0);
	sort(all(vec));

	int n; cin >> n;
	auto l = lower_bound(all(vec), n) - 1, r = upper_bound(all(vec), n);

	if (*(l + 1) == n) {
		cout << 0;
		return 0;
	}

	ll x = n - *l, y = *r - n;
	cout << (x * y) - 1;
}
