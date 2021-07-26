#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> l;
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	ans.assign(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		l.emplace_back(a, i);
	}

	sort(l.begin(), l.end());

	int index = 0, prev = -1e7;
	for (pii i : l) {
		if (i.first == prev) {
			ans[i.second] = index - 1;
		}else{
			ans[i.second] = index++;
		}
		prev = i.first;
	}

	for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
