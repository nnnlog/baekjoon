#include <bits/stdc++.h>

using namespace std;

vector<int> arr(1000);

int main() {
	int cnt = 0, step = 1;
	while (cnt < 1000) {
		for (int i = 0; i < step; i++) if (cnt >= 1000) break; else arr[cnt++] = step;
		step++;
	}

	int a, b, ans = 0; cin >> a >> b;
	for (int i = a - 1; i < b; i++) ans += arr[i];
	cout << ans;
}
