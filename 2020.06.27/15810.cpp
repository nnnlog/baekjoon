#include <bits/stdc++.h>

using namespace std;

vector<long long> li;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long n, m;
	cin >> n >> m;

	while (n--) {
		long long a;
		cin >> a;
		li.push_back(a);
	}

	long long l = 0, r = 1e12;
	while (l < r) {
		long long mid = l + r >> 1, cnt = 0;
		for (const auto &a : li) cnt += mid / a;

		if (cnt < m) l = mid + 1;
		else r = mid;
	}

	cout << (l + r >> 1);
}