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

unordered_map<string, set<string>> T;
map<string, int> root;
void solve(int depth, string curr) {
	for (const auto &s : T[curr]) {
		for (int i = 0; i <= depth; i++) cout << "--";
		cout << s << "\n";
		solve(depth + 1, curr + ":" + s);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	while (n--) {
		int k; cin >> k;
		string prv;
		for (int depth = 0; depth < k; depth++) {
			string s; cin >> s;
			if (depth) T[prv].insert(s), prv += ":" + s;
			else {
				prv = s;
				if (!root[s]) root[s] = 1;
			}

		}
	}
	for (const auto &[str, _] : root) cout << str << "\n", solve(0, str);
}
