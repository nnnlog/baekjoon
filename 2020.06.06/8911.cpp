#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string temp;
	getline(cin, temp);

	while (n--) {
		string a;
		getline(cin, a);
		pii from = {0, 0}, to = {0, 0}, current = {0, 0};
		int up = 1, side = 0; //side: 1(right), -1(left)

		for (const char &t : a) {
			if (t == 'F') {
				current.first += up;
				current.second += side;
			} else if (t == 'B') {
				current.first -= up;
				current.second -= side;
			} else if (t == 'L') {
				if (up) {
					side = -1 * up;
					up = 0;
				} else {
					up = side;
					side = 0;
				}
			} else if (t == 'R') {
				if (up) {
					side = up;
					up = 0;
				} else {
					up = -1 * side;
					side = 0;
				}
			}

			from.first = min(from.first, current.first);
			from.second = min(from.second, current.second);

			to.first = max(to.first, current.first);
			to.second = max(to.second, current.second);
		}

		cout << abs(from.first - to.first) * abs(to.second - from.second) << "\n";
		//cout << from.first << ", " << from.second << " " << to.first << ", " << to.second << "\n";
	}
}
