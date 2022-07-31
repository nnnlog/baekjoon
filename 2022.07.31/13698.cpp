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

    vpii vec('Z');
    vec['A'] = {0, 1};
    vec['B'] = {0, 2};
    vec['C'] = {0, 3};
    vec['D'] = {1, 2};
    vec['E'] = {1, 3};
    vec['F'] = {2, 3};
    
    string s;
    cin >> s;
    
    vi curr(4);
    curr[0] = 1, curr[3] = 2;
    for (char c : s) {
        auto [a, b] = vec[c];
        swap(curr[a], curr[b]);
    }
    
    cout << find(all(curr), 1) - curr.begin() + 1 << "\n";
    cout << find(all(curr), 2) - curr.begin() + 1 << "\n";
}
