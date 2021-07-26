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

	int n, m;
	cin >> n >> m;
	unordered_map<string, int> mp;
	while (n--) {
		string s;
		cin >> s;
		mp[s] = 1;
	}
	while (m--) {
		string s;
		cin >> s;
		string tmp;
		for (const auto &c : s) {
			if (c == ',') {
				mp.erase(tmp);
				tmp.clear();
			} else tmp.push_back(c);
		}
		mp.erase(tmp);
		cout << mp.size() << "\n";
	}
}
