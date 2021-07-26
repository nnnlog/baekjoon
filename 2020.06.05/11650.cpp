#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
vector<pii> l;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	while (n--) {
		int a, b; cin >> a >> b;
		l.emplace_back(a, b);
	}

	sort(l.begin(), l.end());

	for (const auto &a : l) cout << a.first << " " << a.second << "\n";
}
