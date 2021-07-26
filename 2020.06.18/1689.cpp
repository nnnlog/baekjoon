#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> l;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	while (n--) {
		int s, e; cin >> s >> e;
		l.emplace_back(s, 1);
		l.emplace_back(e, -1);
	}

	sort(l.begin(), l.end());

	int ans = 0, cnt = 0;
	for (auto i : l) {
		//cout << i.first << i.second << "\n";
		cnt += i.second;
		ans = max(ans, cnt);
	}

	cout << ans;
}
