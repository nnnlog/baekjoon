#include <bits/stdc++.h>

using namespace std;

int main() {
	string l;
	getline(cin, l);

	int ans = 0;
	for (int i = 0; i < l.size(); i++) {
		if ('A' <= l[i] && l[i] <= 'Z' && i % 4) {
			ans += 4 - i % 4;
			for (int j = 0; j < 4 - i % 4; j++) l.insert(i, "0");
		}
	}
	//cout << l << "\n";

	cout << ans;
}