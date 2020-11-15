#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

vector<pii> graph[1001];
vector<int> dist, inQ;

int solve(int start, int goal) {
	dist[start] = 0;
	inQ[start] = 1;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int top = q.front(); q.pop();
		//cout << top << "\n";
		for (const auto &nxt : graph[top]) {
			if (dist[top] + nxt.second < dist[nxt.first]) {
				dist[nxt.first] = dist[top] + nxt.second;
				if (!inQ[nxt.first]) {
					inQ[nxt.first] = 1;
					q.push(nxt.first);
				}
			}
		}
		inQ[top] = 0;
	}


	return dist[goal];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	for (int i = 0; i < m; i++) {
		int a, b, ans;
		cin >> a >> b;
		inQ.assign(1001, 0);
		dist.assign(1001, 1e9);

		cout << solve(a, b) << "\n";
	}
}
