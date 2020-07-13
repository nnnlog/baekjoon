#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d, e;
	cin >> a >> d >> b >> e >> c;
	int ans = min(a, min(b, c));

	for (int mid = 0; mid <= 200000; mid++) {
		int l_remain = d - max(mid - a, 0), r_remain = e - max(mid - c, 0);
		if (l_remain >= 0 && r_remain >= 0) ans = max(ans, min(mid, b + l_remain + r_remain));
	}

	cout << ans;
}
