#include <bits/stdc++.h>
using namespace std;
int gcd(long long a, long long b) {
	if (!b) return a;
	return gcd(b, a % b);
}
int main() {
	long long a, b, v, g;
	cin >> a >> b;
	if (a == b) cout << 0;
	else {
		v = (long long)sqrtl(b) - (long long)sqrtl(a);
		if (!v) cout << 0;
		else {
			g = gcd(v, b - a);
			cout << (v / g) << "/" << (b - a) / g;
		}
	}
}
