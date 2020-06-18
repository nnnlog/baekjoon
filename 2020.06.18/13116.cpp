#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		vector<int> arr(1024);
		int ans = 1;

		a *= 2;
		b *= 2;
		while (a) arr[a /= 2]++;
		while (b) if(arr[b /= 2] == 1) {
			ans = b;
			break;
		};


		cout << ans * 10 << "\n";
	}
}