#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, c;
	cin >> n >> c;
	set<ll> s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	ll l = 0, r = 1e9;
	for (int i = 0; i < 35; i++) {
		ll mid = (l + r) >> 1;
		ll pos = *(s.begin()), f = 0;

		for (int i = 1; i < c; i++) {
			auto it = s.lower_bound(pos + mid);
			if (it == s.end()) {
				f = 1;
				break;
			}

			pos = *it;

			//cout << mid << " " << pos << "\n";
		}

		if (f) r = mid;
		else l = mid + 1;
	}

	cout << ((l + r) >> 1) - 1;
}
