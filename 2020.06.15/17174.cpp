#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	while (n) {
		ans += n;
		n /= m;
	}
	cout << ans;
}