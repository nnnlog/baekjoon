#include <bits/stdc++.h>

using namespace std;

//bool vis[1000000000];

int main() {
	int a, b;
	cin >> a >> b;
	queue<pair<long long, int>> q;
	q.push({a, 1});

	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		if (/*!vis[f.first * 2] && */f.first * 2 <= b) {
			if (f.first * 2 == b) {
				cout << f.second + 1;
				return 0;
			}
			//vis[f.first * 2] = true;
			q.push({f.first * 2, f.second + 1});
		}
		if (/*!vis[f.first * 10 + 1] && */f.first * 10 + 1 <= b) {
			if (f.first * 10 + 1 == b) {
				cout << f.second + 1;
				return 0;
			}
			//vis[f.first * 10 + 1] = true;
			q.push({f.first * 10 + 1, f.second + 1});
		}
	}

	cout << -1;
}