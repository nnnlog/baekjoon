#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> mp = {
		{'a',  1},
		{'b',  2},
		{'k',  3},
		{'d',  4},
		{'e',  5},
		{'g',  6},
		{'h',  7},
		{'i',  8},
		{'l',  9},
		{'m',  10},
		{'n',  11},
		{'z', 12}, //ng
		{'o',  13},
		{'p',  14},
		{'r',  15},
		{'s',  16},
		{'t',  17},
		{'u',  18},
		{'w',  19},
		{'y',  20},
};

vector<string> l;

int cmp(const string &a, const string &b) {
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		if (mp[a[i]] != mp[b[i]]) {
			return mp[a[i]] < mp[b[i]];
		}
	}
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < a.size() - 1; j++) {
			if (a[j] == 'n' && a[j + 1] == 'g') {
				a[j] = 'z';
				a.erase(j + 1, 1);
				--j;
			}
		}
		l.emplace_back(a);
	}

	sort(l.begin(), l.end(), cmp);

	for (auto a : l) {
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == 'z') {
				a[j] = 'n';
				a.insert(j + 1, "g");
			}
		}
		cout << a << "\n";
	}
}
