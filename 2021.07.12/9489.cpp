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
		int n, k; cin >> n >> k;
		if (!n && !k) return 0;
		unordered_map<int, int> parent_id, group_id;
		parent_id[0] = -1;
		int gid = 0;
		vi vec(n);
		for (auto &i : vec) cin >> i;
		queue<int> par, curr;
		for (int i = 0; i < n; i++) {
			if (!i) par.push(vec[i]), parent_id[vec[i]] = 0, group_id[vec[i]] = ++gid;
			else {
				if (vec[i - 1] + 1 == vec[i]) parent_id[vec[i]] = parent_id[vec[i - 1]], group_id[vec[i]] = group_id[vec[i - 1]];
				else {
					if (par.empty()) par.swap(curr);
					int p = par.front(); par.pop();
					parent_id[vec[i]] = p;
					group_id[vec[i]] = ++gid;
				}
				curr.push(vec[i]);
			}
		}

		int ans = 0;
		for (int i : vec) if (group_id[i] != group_id[k] && parent_id[parent_id[i]] == parent_id[parent_id[k]]) ++ans;
		cout << ans << "\n";
	}
}
