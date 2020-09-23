#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];

	//sort(vec.begin(), vec.end());

	int gcd = 0;
	for (int i = 1; i < n; i++) {
		int diff = vec[i] - vec[i - 1];
		gcd = __gcd(gcd, diff);
	}
	cout << (vec.back() - vec[0]) / gcd - n + 1;
}
