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
	if (s.size() <= 25) cout << s;
	else {
		string a = s.substr(11, n - 22);
		if (a.find('.') == string::npos || a.find('.') + 1 == a.size()) cout << s.substr(0, 11) << "..." << s.substr(n - 11);
		else cout << s.substr(0, 9) << "......" << s.substr(n - 10);
	}
}
