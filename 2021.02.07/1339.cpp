#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vector<string> vec(n);
	map<char, ll> mp;
	for (auto &i : vec) {
		cin >> i;
		reverse(all(i));
		for (int j = 0; j < i.size(); j++) mp[i[j]] += pow(10, j);
		reverse(all(i));
	}

	vector<pair<ll, char>> cnt;
	for (const auto &[c, s] : mp) cnt.emplace_back(s, c);

	sort(all(cnt), greater<>());
	map<char, int> table;
	int k = 10;
	for (const auto &[i, c] : cnt) table[c] = --k;//, cout << c << " " << i << "\n";

	ll ans = 0;
	for (const auto &s : vec) {
		string a;
		for (const auto &c : s) a.push_back(table[c] + '0');
		ans += atoll(a.c_str());
	}

	cout << ans;
}
