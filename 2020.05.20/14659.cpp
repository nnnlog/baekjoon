#include <bits/stdc++.h>

using namespace std;

queue<int> s;
int ans = 0;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		while (!s.empty() && s.front() <= a) s.pop();
		s.push(a);

		ans = max(ans, (int)s.size() - 1);
	}

	cout << ans;
}
