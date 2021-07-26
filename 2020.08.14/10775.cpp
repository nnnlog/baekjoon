#include <bits/stdc++.h>

using namespace std;

int UF[100000];

int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int g, p, ans = 0; cin >> g >> p;
	for (int i = 0; i <= g; i++) UF[i] = i;
	for (; ans < p; ans++) {
		int a; cin >> a;
		if (!find(a)) {
			break;
		}
		UF[find(a)]--;
	}

	cout << ans;
}
