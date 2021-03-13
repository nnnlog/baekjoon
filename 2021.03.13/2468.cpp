#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

pi moved[4] = {pi(1, 0), pi(0,1), pi(-1,0), pi(0,-1)};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, mh = 0, nh = 101; cin >> n;
	
	int grid[100][100];
	
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> grid[x][y];
			mh = max(mh, grid[x][y]);
			nh = min(nh, grid[x][y]);
		}
	}
	
	int cnt = 0;
	for (int i = nh - 1; i <= mh; i++) {
		int t = 0, visit[100][100] = { 0, };
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (visit[x][y]) continue;
				if (grid[x][y] <= i) continue;
				queue<pi> q; q.push(pi(x, y));
				visit[x][y] = 1;
				while (!q.empty()) {
					pi c = q.front(); q.pop();
					for (pi mv : moved) {
						int dx = c.first + mv.first, dy = c.second + mv.second;
						if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
						if (visit[dx][dy]) continue;
						if (grid[dx][dy] <= i) continue;
						visit[dx][dy] = 1;
						q.push(pi(dx, dy));
					}
				}
				
				t++;
			}
		}
		
		cnt = max(cnt, t);
	//			cout << i << " " << t << endl;
	}
	
	cout << cnt;
}
