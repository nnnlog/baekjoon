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

	string s; cin >> s;
	for (int len = 1; len <= 3; len++) {
		int first = atoi(s.substr(0, len).c_str());
		string nxt = to_string(first + 1);
		int i = len;
		int f = 0;
		for (; i + nxt.size() <= s.size();) {
			int curr = atoi(s.substr(i, nxt.size()).c_str());
			if (to_string(curr) != nxt) {
				f = 1;
				break;
			}
			i += nxt.size();
			nxt = to_string(curr + 1);
		}
		if (!f && i == s.size()) {
			cout << first << " " << atoi(nxt.c_str()) - 1;
			return 0;
		}
	}
	assert(0);
}
