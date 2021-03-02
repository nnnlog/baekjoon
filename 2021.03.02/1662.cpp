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

	string s;
	getline(cin, s);
	int prv = 0, sz = 0;
	stack<int> cnt, comp;
	for (const auto &c : s) {
		if (c == '(') {
			cnt.push(sz - 1);
			comp.push(prv);
			sz = 0;
		} else if (c == ')') {
			cnt.push(sz), sz = 0;
			int o = cnt.top();
			cnt.pop();
			assert(!comp.empty());
			o *= comp.top();
			o += cnt.top();
			cnt.pop();
			comp.pop();
			sz = o;
		} else {
			++sz;
			prv = c - '0';
		}
	}
	cnt.push(sz);
	cout << cnt.top();
}
