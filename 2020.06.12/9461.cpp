#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull memo[101];
ull solve(int n) {
	if (n <= 3) return 1;
	if (n <= 5) return 2;
	if (memo[n]) return memo[n];
	return memo[n] = solve(n - 1) + solve(n - 5);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a; cin >> a;
		cout << solve(a) << "\n";
	}
}
