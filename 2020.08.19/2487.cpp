#include <bits/stdc++.h>

using namespace std;

vector<int> vec(20001), chk(20001);

int dfs(int curr) {
	if (chk[curr]) return 0;
	return (chk[curr] = 1) + dfs(vec[curr]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> vec[i];

	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		long long tmp = dfs(i);
		ans = tmp * ans / __gcd(tmp, ans);
	}

	cout << ans;
}
