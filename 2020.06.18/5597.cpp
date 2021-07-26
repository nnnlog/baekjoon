#include <bits/stdc++.h>

using namespace std;

int chk[31];

int main() {
	for (int i = 0; i < 28; i++) {
		int a; cin >> a;
		chk[a] = 1;
	}

	for (int i = 1; i <= 30; i++) if (!chk[i]) cout << i << "\n";
}