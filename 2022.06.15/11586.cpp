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
    vector<string> vec(n);
    for (auto &s : vec) cin >> s;
    int a; cin >> a;
    if (a == 1) {
        for (auto &s : vec) cout << s << "\n";
    }
    if (a == 2) {
        for (auto &s : vec) reverse(all(s)), cout << s << "\n";
    }
    if (a == 3) {
        reverse(all(vec));
        for (auto &s : vec) cout << s << "\n";
    }
}

