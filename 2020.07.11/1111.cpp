#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> v;

    int n;
    cin >> n;
    if (n == 1) {
        cout << "A";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int a = 0, b;
    if (n == 2) cout << (v[0] == v[1] ? to_string(v[0]) : "A");
    else {
        int x = v[0], y = v[1], z = v[2];
        if (y - x == 0) b = y;
        else {
            a = (z - y) / (y - x);
            b = y - (x * a);
        }

        bool fail = false;
        for (int i = 1; i < n - 1; i++) {
            if (v[i] * a + b != v[i + 1]) {
                fail = true;
                break;
            }
        }

        cout << (fail ? "B" : to_string(v.back() * a + b));
    }
}