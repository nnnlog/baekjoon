#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b, k, sel; cin >> a >> b;
    k = b / a;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0 && gcd(i, k / i) == 1) sel = i;
    }

    cout << sel * a << " " << (a * (k / sel));
}
