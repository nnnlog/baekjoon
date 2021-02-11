#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

ld shoelace(vpll coordinates) {
	long double ans = 0;
	for (int i = 0; i < coordinates.size() - 1; i++)
		ans += coordinates[i].first * coordinates[i + 1].second,
				ans -= coordinates[i].second * coordinates[i + 1].first;


	return round(abs(ans) * 50) / 100.0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vpll vec(n);
	for (auto &[a, b] : vec) cin >> a >> b;
	cout << fixed;
	cout.precision(1);
	vec.emplace_back(*vec.begin());
	cout << shoelace(vec);
}
