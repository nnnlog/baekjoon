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

    int n, s;
    cin >> n >> s;
    s--;
    vi X(n);
    for (int &i: X) cin >> i;
    vi H(n);
    for (int &i: H) cin >> i;
    int l = s, r = s;
    queue<int> Q;
    set<int> S;
    for (int i = 0; i < n; i++) if (i != s) S.insert(i);
    Q.push(s);
    while (!Q.empty()) {
        int f = Q.front(); Q.pop();
        l = min(l, f);
        r = max(r, f);

        {
            auto it = S.lower_bound(f);
            if (it != S.end()) {
                int i = *it;
                if (X[i] - X[f] <= H[f]) {
                    S.erase(i);
                    Q.push(i);
                    H[i] = max(H[i], H[f] - (X[i] - X[f]));
                }
            }
        }
        {
            auto it = S.upper_bound(f);
            if (!S.empty() && it != S.begin()) {
                int i = *--it;
                if (X[f] - X[i] <= H[f]) {
                    S.erase(i);
                    Q.push(i);
                    H[i] = max(H[i], H[f] - (X[f] - X[i]));
                }
            }
        }
    }
    for (int i = l; i <= r; i++) cout << i + 1 << " ";
}
