#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		int v = a % 10;
		for (int i = 1; i < b; i++) {
			v *= a;
			v %= 10;
		}
		cout << (v ? v : 10) << "\n";
	}
}
