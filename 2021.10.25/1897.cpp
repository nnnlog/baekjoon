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

	int n;
	string a;
	cin >> n >> a;

	unordered_map<string, int> mp;
	mp[a] = 1;

	vector<string> vec(n);
	for (auto &s : vec) cin >> s;
	sort(all(vec), [](const auto &a, const auto &b) {
		return a.size() < b.size();
	});

	for (const auto &s : vec) {
		if (s.size() < 2) continue;
		for (int i = 0; i < s.size(); i++) {
			string chk = s;
			chk.erase(i, 1);
			if (mp.count(chk)) {
				mp[s] = 1;
				break;
			}
		}
	}

	string ans;
	for (const auto &[s, _] : mp) {
		if (ans.size() < s.size()) ans = s;
	}
	cout << ans;
}
