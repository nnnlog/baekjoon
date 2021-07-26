#include <bits/stdc++.h>

using namespace std;

int arr[100][100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];


	for (int i = 0; i < n; i++) {
		int vis[100] = { 0, };
		for (int j = 0; j < n; j++) {
			if (!arr[i][j]) continue;

			vis[j] = 1;
			queue<int> q;
			q.push(j);
			while (!q.empty()) {
				int from = q.front();
				q.pop();
				for (int to = 0; to < n; to++) {
					if (vis[to]) continue;
					if (!arr[from][to]) continue;
					vis[to] = 1;
					q.push(to);
				}
			}
		}

		for (int j = 0; j < 100; j++) arr[i][j] = vis[j] || arr[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << arr[i][j] << " ";
		cout << "\n";
	}
}
