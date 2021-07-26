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

	int n, ans = 0; cin >> n;
	map<int, vi> mp;
	while (n--) {
		int a, b; cin >> a >> b;
		mp[b].emplace_back(a);
	}
	priority_queue<int> pq;
	for (int i = 10000; i > 0; --i) {
		for (const auto &w : mp[i]) pq.push(w);
		if (!pq.empty()) ans += pq.top(), pq.pop();
	}

	cout << ans;
}
