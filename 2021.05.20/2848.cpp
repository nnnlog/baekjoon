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

	vector<vector<char>> graph('z' + 1);
	map<char, int> ok;

	int n; cin >> n;
	string prv; cin >> prv;
	for (auto c : prv) if (!ok.count(c)) ok[c] = 0;
	for (int i = 1; i < n; i++) {
		string curr; cin >> curr;
		for (auto c : curr) if (!ok.count(c)) ok[c] = 0;
		int chk = 0;
		for (int j = 0; j < min(prv.size(), curr.size()); j++)
			if (prv[j] != curr[j]) {
				chk = 1;
				graph[prv[j]].emplace_back(curr[j]);
				++ok[curr[j]];
				break;
			}
		if (!chk && prv.size() > curr.size()) {
			cout << "!";
			return 0;
		}
		curr.swap(prv);
	}
	queue<char> q;
	for (auto [c, t] : ok) if (!t) q.push(c);
	int f = q.size() >= 2;
	string ans;
	while (!q.empty()) {
		auto top = q.front(); q.pop();
		ans += top;
		for (auto nxt : graph[top]) if (!--ok[nxt]) q.push(nxt);
		f |= q.size() >= 2;
	}
	int s = 0;
	for (auto [c, t] : ok) s += t;
	if (s) {
		cout << '!';
		return 0;
	}
	if (f) {
		cout << '?';
		return 0;
	}
	cout << ans;
}
