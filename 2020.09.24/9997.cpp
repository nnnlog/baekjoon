#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> vec;

int solve(int sz, int vis) {
	if (sz == n) {
		if (vis == (1 << 26) - 1) return 1;
		else return 0;
	}
	return solve(sz + 1, vis | vec[sz]) + solve(sz + 1, vis);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		ll tmp = 0;
		for (const auto &c : str) tmp |= 1 << (c - 'a');
		vec.emplace_back(tmp);
	}

	cout << solve(0, 0);
}
