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

	vi lim = {100, 100, 200, 200, 300, 300, 400, 400, 500};
    int s = 0;
    for (int i = 0; i < 9; i++) {
        int a; cin >> a;
        if (lim[i] < a) return cout << "hacker", 0;
        s += a;
    }
    cout << (s >= 100 ? "draw" : "none");
}
