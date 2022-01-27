#include <bits/stdc++.h>

using namespace std;

vector<int> l;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	l.resize(n);
	while (q--) {
		int start, gap; cin >> start >> gap;
		for (int i = start - 1; i < n; i += gap) l[i] = 1;
	}
	int ans = 0;
	for (const int& a : l) if (!a) ans++;

	cout << ans;
}
