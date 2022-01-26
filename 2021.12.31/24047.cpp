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

    int n, k;
    cin >> n >> k;
    vi vec(n);
    for (int &i: vec) cin >> i;
    vi ok;
    for (int i = 0; i < n - 1; i++) if (vec[i] > vec[i + 1]) ok.push_back(i);
    for (int i = n - 1; i >= 0; i--) {
        vi nxt;
        int x = 0;
        for (int j : ok) {
            if (x > j) continue;
            x = j;
            for (; x < i; x++) {
                if (vec[x] < vec[x + 1]) break;
                swap(vec[x], vec[x + 1]);
                if (!--k) {
                    for (int a : vec) cout << a << " ";
                    return 0;
                }
            }
            for (int go = j; go < x; go++) {
                if (go > 0 && vec[go - 1] > vec[go]) nxt.push_back(go - 1);
            }
        }
        ok.swap(nxt);
    }

    cout << -1;
}
