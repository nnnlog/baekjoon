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
	cin >> s;

	vpii pairs;
	stack<int> open;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') open.push(i);
		else if (s[i] == ')') pairs.emplace_back(open.top(), i), open.pop();
	}

	vector<string> ans;
	int sz = pairs.size();
	for (int i = 1; i < (1 << sz); i++) {
		string tmp = s;
		for (int j = 0; j < sz; j++)
			if (i & (1 << j)) {
				tmp[pairs[j].first] = '_';
				tmp[pairs[j].second] = '_';
			}

		ans.emplace_back("");
		for (char c : tmp) if (c != '_') ans.back().push_back(c);
	}
	sort(all(ans));
	ans.erase(unique(all(ans)), ans.end());
	for (const auto &a : ans) cout << a << "\n";
}
