#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
	ull N;
	cin >> N;

	vector <vector<ull>> element;
	for (ull bit = 1; bit <= 1ULL << 10ULL; bit++) {
		vector <ull> available;
		for (ull j = 0; j <= 9; j++)
			if (bit & (1ULL << j)) available.push_back(j);
		element.push_back(available);
	}

	sort(element.begin(), element.end(), [](const auto &a, const auto &b) {
		return a.size() < b.size();
	});

	vector <string> ans;
	ull size = 0;
	for (const auto &vec : element) {
		if (size && vec.size() != size) break;
		unordered_map<ull, bool> vis;
		queue <pair<ull, string>> q;
		for (const ull &u : vec)
			if (u && !vis[u % N]) {
				q.push({u % N, string(1, u + '0')});
				vis[u % N] = true;
			}

		while (!q.empty()) {
			auto current = q.front();
			q.pop();
			if (!current.first) {
				size = vec.size();
				ans.push_back(current.second);
				break;
			}
			for (const ull &u : vec) {
				string tmp = current.second;
				tmp.push_back('0' + u);
				ull tmp_num = (current.first * 10 + u) % N;
				if (vis[tmp_num % N]) continue;
				q.push({tmp_num, tmp});
				vis[tmp_num % N] = 1;
			}
		}
	}

	sort(ans.begin(), ans.end(), [](const auto &a, const auto &b) {
		if (a.size() == b.size()) return a < b;
		return a.size() < b.size();
	});
	cout << *(ans.begin());
}
