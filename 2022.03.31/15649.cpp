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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vi vec(n);
    iota(all(vec), 1);
    int skip = 1;
    for (int i = 1; i <= n - m; i++) skip *= i;
    int curr = skip;
    do {
        if (!--curr) {
            curr = skip;
            for (int i = 0; i < m; i++) cout << vec[i] << " ";
            cout << "\n";
        }
    } while (next_permutation(all(vec)));
}
