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
	
	int n; cin >> n;
	string s; cin >> s;
	reverse(all(s));
	int empty = 0, end = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' && !end) ++empty;
		else end = 1;
	}
	int m; cin >> m;
	cout << (empty >= m || empty == n ? "YES" : "NO");
}
