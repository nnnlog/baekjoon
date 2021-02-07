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

string s;

int solve(string curr, int vis) {
	int ret = 0;
	if (curr.size() != s.size()) {
		unordered_map<char, bool> mp;
		for (int j = 0; j < s.size(); j++) {
			if (!(vis & (1 << j)) && (curr.empty() || curr.back() != s[j]) && !mp[s[j]])
				curr.push_back(s[j]), mp[s[j]] = true, ret += solve(curr, vis | (1 << j)), curr.pop_back();
		}
		return ret;
	}

	ret = 1;
	//cout << curr << "\n";

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s;
	cout << solve("", 0);
}
