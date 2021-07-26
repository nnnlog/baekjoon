#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> vec;

int dis(pii a, pii b) {
	return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int single_dis(int a, int b) {
	return pow(a - b, 2);
}

int solve(int start, int end) {
	//printf("%d %d\n", start, end);
	//if (start + end <= 1) return 0;
	if (end - start == 2) return dis(vec[start], vec[start + 1]);
	if (end - start == 3)
		return min(dis(vec[start], vec[start + 1]),
		           min(dis(vec[start], vec[start + 2]), dis(vec[start + 1], vec[start + 2])));

	int mid = (vec[(start + end) / 2].first + vec[(start + end - 1) / 2].first) / 2;
	int ans = min(solve(start, (start + end) / 2), solve((start + end) / 2, end));

	//printf("* %d %d -> %d: start\n", start, end, ans);
	vector<pii> new_vec;
	for (int i = start; i < end; i++) {
		if (single_dis(vec[i].first, mid) < ans) new_vec.push_back(vec[i]);
	}

	//printf("* ans: %d\n", ans);
	sort(new_vec.begin(), new_vec.end(), [](const auto &a, const auto &b) {
		return a.second < b.second;
	});

	//printf("* new vec sz: %zu\n", new_vec.size());
	for (int i = 0; i < (int)new_vec.size() - 1; i++)
		for (int j = i + 1; j < new_vec.size() && single_dis(new_vec[i].second, new_vec[j].second) < ans; j++) {
			ans = min(ans, dis(new_vec[i], new_vec[j]));
		}
	//printf("* end 3\n");

	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.emplace_back(a, b);
	}

	sort(vec.begin(), vec.end());

	cout << solve(0, n);
}
