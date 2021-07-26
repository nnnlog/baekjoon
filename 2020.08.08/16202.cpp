#include <bits/stdc++.h>

using namespace std;

vector<int> UF;
vector<pair<int, int>> nodes;

int find(int x) {
	return UF[x] = UF[x] == x ? x : find(UF[x]);
}

int merge(int a, int b) {
	int x = find(a), y = find(b);
	//cout << "Enter (" << a << " " << b << ")\n";
	if (x != y) {
		//cout << max(x,y) << " -> " << min(x, y) << "\n";
		UF[max(x, y)] = min(x, y);
		return 1;
	}
	return 0;
}

void reset(int size) {
	for (int i = 1; i <= size; i++) UF[i] = i;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;

	UF.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		nodes.emplace_back(a, b);
	}

	int fail = false;
	for (int i = 0; i < k; i++) {
		if (fail) cout << "0 ";
		else {
			int sum = 0;
			reset(n);
			for (int j = i; j < m; j++)
				if (merge(nodes[j].first, nodes[j].second))
					sum += j + 1;

			for (int j = 1; j <= n; j++) {
				//cout << find(j) << " ";
				if (find(j) != 1) {
					fail = true;
					//break;
				}
			}
			//cout << "\n";

			cout << (fail ? 0 : sum) << " ";
		}
	}
}
