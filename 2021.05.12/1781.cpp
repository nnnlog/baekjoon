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
	map<int, vi, greater<>> mp;
	while (n--) {
		int a, b; cin >> a >> b;
		mp[a].push_back(b);
	}
	mp[0] = {};
	ll ans = 0;
	priority_queue<int> pq;
	int prv = mp.begin()->first;
	for (const auto &[a, vec] : mp) {
		int diff = prv - a;
		while (diff-- && !pq.empty()) ans += pq.top(), pq.pop();
		for (const auto &i : vec) pq.push(i);
		prv = a;
	}
	cout << ans << "\n";
}
