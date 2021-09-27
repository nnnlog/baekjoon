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

pair<string, int> parse() {
	string ret;
	getline(cin, ret);
	ret.erase(0, ret.find('"') + 1);
	int idx = ret.find('"');
	int p = atoi(ret.substr(idx + 1).c_str());
	ret.erase(idx);
	return {ret, p};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k >> ws;
	priority_queue<pair<string, int>, vector<pair<string, int>>, greater<>> pq;
	while (n--) pq.push(parse());
	priority_queue<pair<int, pair<string, int>>, vector<pair<int, pair<string, int>>>, greater<>> lazy;
	while (m--) {
		int t; cin >> t;
		lazy.emplace(t, parse());
	}
	pq.emplace("Jane Eyre", k);
	ll ans = 0;
	while (!pq.empty()) {
		while (!lazy.empty() && lazy.top().first <= ans) pq.push(lazy.top().second), lazy.pop();
		ans += pq.top().second;
		if (pq.top().first == "Jane Eyre") {
			cout << ans;
			return 0;
		}
		pq.pop();
	}
}
