#include <bits/stdc++.h>

using namespace std;

int borrow[100], return_[100];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		borrow[a]++;
		return_[b]++;
	}

	int k, cnt;
	cin >> k;

	cnt = k;

	for (int day = 1; day <= 31; day++) {
		cnt += return_[day] - borrow[day];
		if (cnt < 0) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;
}
