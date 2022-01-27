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

	int n, k = 0; cin >> n;
	vector<tuple<int, int, int, int>> vec(n);
	map<int, int, greater<>> mp;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		mp[c] = 1;
		vec.emplace_back(a, b, c, i);
	}
	for (auto &[a, b] : mp) b = k++;
	sort(all(vec), greater<>());
	vi dp(n);
	vpii track(n);
	for (int i = 0; i < n; i++) {
		int h = get<1>(vec[i]), w = mp[get<2>(vec[i])];
		track[w] = {get<3>(vec[i]), -1};
		for (int j = 0; j < w; j++) if (dp[w] < dp[j]) dp[w] = dp[j], track[w].second = j;
		dp[w] += h;
	}
	vi ans;
	int idx = max_element(all(dp)) - dp.begin();
	while (1) {
		ans.emplace_back(track[idx].first);
		idx = track[idx].second;
		if (idx < 0) break;
	}
	cout << ans.size() << "\n";
	for (auto i : ans) cout << i + 1 << "\n";
}
