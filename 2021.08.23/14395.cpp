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

	ll s, t; cin >> s >> t;
	unordered_map<ll, string> ans;
	queue<pair<ll, string>> Q;
	if (s == t) {
		cout << 0;
		return 0;
	}
	Q.emplace(s, "");
	auto comp = [&](string a, string b) {
		if (a.size() == b.size()) return a < b;
		return a.size() < b.size();
	};
	auto push = [&](ll a, string nxt) {
		if (!ans.count(a) ^ comp(nxt, ans[a])) ans[a] = nxt, Q.emplace(a, nxt);
	};
	while (!Q.empty()) {
		auto f = Q.front(); Q.pop();
		push(f.first + f.first, f.second + "+");
		push(f.first - f.first, f.second + "-");
		push(f.first * f.first, f.second + "*");
		if (f.first) push(f.first / f.first, f.second + "/");
	}
	if (ans.count(t)) cout << ans[t];
	else cout << -1;
}
