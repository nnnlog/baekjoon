#include <bits/stdc++.h>

using namespace std;

long long mp[1000][1000];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	long long n, targ = 0;
	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++){
			cin >> mp[x][y];
			targ += mp[x][y];
	}
	long long l = 0, r = 1e7;
	while (l < r) {
		long long mid = l + r >> 1, cnt = 0;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				cnt += min(mp[x][y], mid);

		if (cnt < targ / 2 + targ % 2) l = mid + 1;
		else r = mid;
		
	}

	cout << (l + r >> 1);
}
