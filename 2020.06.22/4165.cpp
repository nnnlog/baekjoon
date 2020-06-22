#include <bits/stdc++.h>

using namespace std;

int cnt(long a) {
	int cnt = 0;
	a *= 10;
	while (a /= 10) if (a % 10 == 5) cnt++;
	return cnt;
}

int main() {
	long long n, k, add = 1; cin >> n >> k;
	++n;
	
	while (cnt(n) < k) {
		while ((n / add) % 10 == 5) add *= 10;
		n += add;
		//cout << n << "\n";
	}
	cout << n;
}