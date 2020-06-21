#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0); cout.tie(0);
	string start; cin >> start;
	list<char> ans(start.begin(), start.end());
	int n; cin >> n;
	auto cursor = ans.end();
	while (n--) {
		char t; cin >> t;
		if (t == 'P') {
			char push; cin >> push;
			ans.insert(cursor, push);
		} else if (t == 'B' && cursor != ans.begin()) {
			cursor = ans.erase(--cursor);
		}
		else if (t == 'L' && cursor != ans.begin()) --cursor;
		else if (t == 'D' && cursor != ans.end()) ++cursor;
	}

	for (const auto &c : ans) cout << c;
}