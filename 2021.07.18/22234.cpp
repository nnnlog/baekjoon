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

	int n, t, w;
	cin >> n >> t >> w;
	queue<pii> Q;
	while (n--) {
		int a, b;
		cin >> a >> b;
		Q.emplace(a, b);
	}
	int m;
	cin >> m;
	map<int, pii> mp;
	while (m--) {
		int a, b, tt;
		cin >> a >> b >> tt;
		mp[tt] = {a, b};
	}
	pii proc;
	int alloc = 0;
	for (int i = 0; i < w; i++) {
		if (mp.count(i)) Q.emplace(mp[i]);
		if (proc.first) {
			--alloc;
			if (!--proc.second) {
				alloc = 0;
			} else if (!alloc) {
				if (proc.second) {
					Q.emplace(proc);
				}
			}
		}
		if (!alloc) {
			alloc = t;
			proc = Q.front();
			Q.pop();
		}

		cout << proc.first << "\n";
	}
}
