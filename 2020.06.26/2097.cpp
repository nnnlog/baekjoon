#include <bits/stdc++.h>

using namespace std;

int main() {
    double n;
    cin >> n;
    double one = ceil(sqrtf(n));
    double two = ceil(n / one);
    //cout << one << " " << two << "\n";
    cout << (max(one - 1, 1.0) + max(two - 1, 1.0)) * 2;
}