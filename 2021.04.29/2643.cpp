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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vpii vec(n);
	for (auto &[a, b] : vec) {
		cin >> a >> b;
		if (a < b) swap(a, b);
	}
	sort(all(vec), greater<>());
	vi dp(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (vec[j].second <= vec[i].second)
				dp[j] = max(dp[j], dp[i] + 1);
		}
	}
	cout << *max_element(all(dp));
}
