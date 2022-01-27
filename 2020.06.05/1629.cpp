#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
	ull a, b, c, ans = 1; cin >> a >> b >> c;
    
	while (b) {
		ull k = 1, now = 1;
		while (b >= now) {
			k *= (now == 1 ? a : k);
			k %= c;

			now *= 2;
		}
		
		b -= now / 2;
		ans *= k;
		ans %= c;
	}
	cout << ans;
}
