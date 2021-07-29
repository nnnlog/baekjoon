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

	vi vec(20);
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int a = 0;
		if (s != "all" && s != "empty") cin >> a;
		--a;
		if (s == "add") vec[a] = 1;
		if (s == "remove") vec[a] = 0;
		if (s == "check") cout << vec[a] << "\n";
		if (s == "toggle") vec[a] = !vec[a];
		if (s == "all") vec.assign(20, 1);
		if (s == "empty") vec.assign(20, 0);
	}
}
