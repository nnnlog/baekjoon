#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vector<pii> vec;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		vec.emplace_back(a, 1);
		vec.emplace_back(b, 0);
	}

	sort(all(vec));

	ll open = 0, first = 0, ans = 0;
	for (const auto &[a, b] : vec) {
		if (b) {
			if (!open) first = a;
			open++;
		} else {
			--open;
			if (!open) {
				ans += a - first;
			}
		}
	}

	cout << ans;
}
