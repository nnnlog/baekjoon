#include <bits/stdc++.h>

using namespace std;

vector<int> l;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		l.emplace_back(a);
	}

	sort(l.begin(), l.end());

	for (int i = 0; i < m; i++) {
		int s, e; cin >> s >> e;
		cout << upper_bound(l.begin(), l.end(), e) - lower_bound(l.begin(), l.end(), s) << "\n";
	}
}
