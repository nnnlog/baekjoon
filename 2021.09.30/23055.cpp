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

    int n; cin >> n;
    for (int i = 0; i < n; i++) cout << '*';
    if (n == 1) return 0;
    cout << '\n';
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (!j || j + 1 == n) cout << '*';
            else if (i == j || n - i - 1 == j) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < n; i++) cout << '*';
}
