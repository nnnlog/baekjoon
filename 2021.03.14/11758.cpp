#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

ll solve(vpii vec) {
	assert(vec.size() >= 3);
	vec.push_back(vec[0]);
	ll ret = 0;
	for (int i = 0; i < vec.size() - 1; i++) {
		ret += vec[i].first * vec[i + 1].second;
	}
	for (int i = 0; i < vec.size() - 1; i++) {
		ret -= vec[i].second * vec[i + 1].first;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vpii vec(3);
	for (auto &[a, b] : vec) cin >> a >> b;

	ll t = solve(vec);
	if (t > 0) cout << "1";
	else if (t < 0) cout << "-1";
	else cout << "0";
}
