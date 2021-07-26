#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	cout << fixed;
	cout.precision(4);

	int n; cin >> n;
	while (n--) {
		double a; cin >> a;
		string op; cin >> op;

		if (op == "kg") cout << a * 2.2046 << " lb";
		else if (op == "lb") cout << a * 0.4536 << " kg";
		else if (op == "l") cout << a * 0.2642 << " g";
		else cout << a * 3.7854 << " l";
		cout << "\n";
	}
}