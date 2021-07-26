#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll a, b;
	cin >> a >> b;
	--a;
	vector<ll> cnt(55);
	for (ll i = 0; i < 55; i++) {
		ll curr = 1LL << i;
		ll n = a / curr, m = b / curr;
		if (m) {
			cnt[i] = m - n;
			//cout << i << " " << cnt[i] << "\n";
		}
	}

	ll ans = 0, sum = 0;
	for (ll i = 53; i >= 0; i--) {
		ll curr = 1LL << i;
		cnt[i] -= sum;
		sum += cnt[i];
		ans += cnt[i] * curr;

		//cout << i << " " << cnt[i] << "\n";
	}

	cout << ans;
}
