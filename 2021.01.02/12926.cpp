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
	/*ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);*/

	ll n, x0, a, b; cin >> n >> x0 >> a >> b;

/*
	int prev = x0;
	vi test;
	for (int i = 0; i < n; i++) {
		if (i) prev = ((ll)prev * (ll)a + (ll)b) % 1000000007LL;
		test.push_back(prev);
	}
	sort(all(test));
	for (const auto &i : test) cout << i << "\n";
*/
	int Q; cin >> Q;

	vi query;
	vpii section;
	while (Q--) {
		int q; cin >> q;
		query.push_back(q);
		section.emplace_back(0, 1000000007);
	}

	while (1) {
		//break;
		int f = 0;
		unordered_map<int, pair<vi, int>> mp;
		for (int i = 0; i < section.size(); i++) {
			if (section[i].first >= section[i].second) continue;
			mp[(section[i].first + section[i].second) >> 1].first.push_back(i);
			f = 1;
		}
		//printf("%d\n", f);

		if (!f) break;
		int prev = x0;
		for (int i = 0; i < n; i++) {
			if (i) prev = ((ll)prev * (ll)a + (ll)b) % 1000000007LL;
			for (auto &[value, info] : mp) {
				if (value >= prev) info.second++;
			}
		}

		for (const auto &[value, info] : mp) {
			for (const auto &i : info.first) {
				if (info.second > query[i]) {
					section[i].second = value;
				} else {
					section[i].first = value + 1;
				}
				//cout << i << " " << section[i].first << " " << section[i].second << "\n" << endl;
			}
		}
	}

	ll sum = 0;
	for (const auto &[l, r] : section) sum += (ll)((l + r) >> 1);
	//cout << sum;
	printf("%lld", sum);
}
