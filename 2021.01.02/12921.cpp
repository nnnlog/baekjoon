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
		vpii mid;
		for (int i = 0; i < section.size(); i++) {
			if (section[i].first >= section[i].second) continue;
			mp[(section[i].first + section[i].second) >> 1].first.push_back(i);
			mid.emplace_back((section[i].first + section[i].second) >> 1, 0);
			f = 1;
		}
		//printf("%d\n", f);
		sort(all(mid));
		mid.erase(unique(all(mid)), mid.end());

		if (!f) break;
		int prev = x0;
		for (int i = 0; i < n; i++) {
			auto it = lower_bound(all(mid), pii(prev, 0));
			if (mid.end() != it) ++it->second;
			prev = ((ll)prev * (ll)a + (ll)b) % 1000000007LL;
		}

		for (int i = 0; i < mid.size(); i++) {
			if (i) mid[i].second += mid[i - 1].second;
			mp[mid[i].first].second = mid[i].second;
		}


		for (const auto &[value, info] : mp) {
			for (const auto &i : info.first) {
				if (info.second > query[i]) {
					section[i].second = value;
				} else {
					section[i].first = value + 1;
				}
				//cout << i << " " << section[i].first << " " << section[i].second << "\n";
			}
		}
	}

	ll sum = 0;
	for (const auto &[l, r] : section) sum += (ll)((l + r) >> 1)/*, cout << (l + r >> 1) << "\n"*/;
	cout << sum;
	//printf("%lld", sum);
}
