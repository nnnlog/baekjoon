#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n, h, w; cin >> n >> h >> w;
    h = max(h, n - h);
    w = max(w, n - w);
    cout << h * w * 4;
}
