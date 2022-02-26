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
    vi vec(n);
    for (int &i : vec) cin >> i;
    vec.push_back(vec.back());
    vi ans(n, -1);
    int last = n;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = last;
        if (vec[i] != vec[i + 1]) ans[i] = i + 1, last = i + 1;
    }
    for (int i : ans) cout << (i == n ? -1 : i + 1) << " ";
}
