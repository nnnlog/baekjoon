#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

vi vec;
bitset<1031926802> B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vec.reserve(1e7);
    B[1] = true;
    for (int i = 1; i <= 1031926801 / 2 + 1; i++) {
        if (B[i]) {
            vec.push_back(i);
            if (i * 2 + 1 <= 1031926801) B[i * 2 + 1] = true;
            if (i * 3 + 1 <= 1031926801) B[i * 3 + 1] = true;
        }
    }

    for (int i = 1031926801 / 2 + 2; i <= 1031926801; i++) {
        if (B[i]) {
            vec.push_back(i);
        }
    }

    int T; cin >> T;
    while (T--) {
        int a; cin >> a;
        cout << vec[--a] << "\n";
    }
}
