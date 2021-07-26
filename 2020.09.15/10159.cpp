#include <bits/stdc++.h>

using namespace std;

vector<int> go_up[201], go_down[201];
int up_known[201], down_known[201];

int up(int a) {
	if (up_known[a]) return 0;
	up_known[a] = 1;
	for (const auto &b : go_up[a]) up_known[a] += up(b);
	return up_known[a];
}

int down(int a) {
	if (down_known[a]) return 0;
	down_known[a] = 1;
	for (const auto &b : go_down[a]) down_known[a] += down(b);
	return down_known[a];
}

int solve(int i) {
	for (int i = 0; i <= 200; i++) up_known[i] = down_known[i] = 0;
	return up(i) + down(i) - 2;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; // a > b
		go_up[b].push_back(a);
		go_down[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) cout << n - solve(i) - 1 << "\n";
}
