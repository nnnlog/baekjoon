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

string s, t;
void dfs() {
	if (t.empty()) return;
	if (t == s) {
		cout << 1;
		exit(0);
	}
	if (t.size() <= s.size()) return;
	string tmp = t;
	if (t[0] == 'B') {
		t.erase(t.begin());
		reverse(all(t));
		dfs();
		t = tmp;
	}
	if (t.back() == 'A') {
		t.pop_back();
		dfs();
		t.push_back('A');
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s >> t;
	dfs();
	cout << 0;
}
