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

vi A = {1, 2, 3, 3, 4, 10}, B = {1, 2, 2, 2, 3, 5, 10};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int a = 0;
        for (int j = 0; j < A.size(); j++) {
            int x; cin >> x;
            a += A[j] * x;
        }
        int b = 0;
        for (int j = 0; j < B.size(); j++) {
            int x; cin >> x;
            b += B[j] * x;
        }
        cout << "Battle " << i << ": ";
        if (a < b) cout << "Evil eradicates all trace of Good\n";
        else if (a == b) cout << "No victor on this battle field\n";
        else cout << "Good triumphs over Evil\n";
    }
}
