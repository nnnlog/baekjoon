#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	unordered_map<int, int> vis;
	queue<pair<int, vi>> q;
	q.push({n, {n}});
	while (!q.empty()) {
		auto f = q.front(); q.pop();
		if (f.first == 1) {
			cout << f.second.size() - 1<< "\n";
			for (const auto &k : f.second) cout << k << " ";
			return 0;
		}
		auto push = [&](int nxt) {
			if (vis[nxt]) return;
			vis[nxt] = 1;
			f.second.push_back(nxt);
			q.push({nxt, f.second});
			f.second.pop_back();
		};
		if (f.first % 3 == 0) push(f.first / 3);
		if (f.first % 2 == 0) push(f.first / 2);
		push(f.first - 1);
	}
}
