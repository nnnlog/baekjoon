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

vpii vec;
int vis[101], g, ans;

void dfs(int k) {
	if (k == g) {
		ans = 1;
		return;
	}
	for (int i = 0; i < vec.size(); i++) {
		if (!vis[i] && ((vec[i].first < vec[k].first && vec[k].first < vec[i].second) ||
		                vec[i].first < vec[k].second && vec[k].second < vec[i].second)) {
			vis[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		--b, --c;
		if (a == 1) {
			vec.emplace_back(b, c);
		} else {
			memset(vis, 0, sizeof vis);
			g = c;
			ans = 0;
			vis[b] = 1;
			dfs(b);

			cout << ans << "\n";
		}
	}
}
