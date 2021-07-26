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

	int n; cin >> n;
	map<int, vi> ed;
	while (n--) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		ed[b].push_back(a);
	}
	priority_queue<int, vi, greater<>> start;
	int l; cin >> l;
	int ans = 0;
	for (const auto &[a, vec] : ed) {
		for (const auto &s : vec) start.push(s);
		while (!start.empty() && start.top() < a - l) start.pop();
		ans = max(ans, (int)start.size());
	}
	cout << ans;
}
