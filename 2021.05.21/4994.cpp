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

	while (1) {
		int n;
		cin >> n;
		if (!n) break;
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		vi vis(n);
		queue<pair<int, string>> q;
		q.push({1, "1"});
		vis[1] = 1;
		while (!q.empty()) {
			auto top = q.front();
			q.pop();
			auto push = [&](int nxt, string nxt2) {
				nxt %= n;
				if (!nxt) {
					cout << nxt2 << "\n";
					return 1;
				}
				if (!vis[nxt]) {
					vis[nxt] = 1;
					q.push({nxt, nxt2});
				}
				return 0;
			};
			if (push(top.first * 10, top.second + "0")) break;
			if (push(top.first * 10 + 1, top.second + "1")) break;
		}
	}
}
