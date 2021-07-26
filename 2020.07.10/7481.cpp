#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int a, b, S, swaped = 0, success = 0;
		cin >> a >> b >> S;

		if (a < b && (swaped = 1)) swap(a, b);

		for (int i = S / a; i >= 0; i--) {
			if ((S - i * a) % b == 0) {
				if (swaped) cout << (S - i * a) / b << " " << i;
				else cout << i << " " << (S - i * a) / b;
				cout << "\n";

				success = 1;
				break;
			}
		}

		if (!success) {
			cout << "Impossible\n";
		}
	}
}