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
    vi A(n);
    for (int &i: A) cin >> i;
    vi B(n);
    for (int &i: B) {
        cin >> i;
    }

    vi ok;
    for (int i = 0; i < n - 1; i++) if (A[i] > A[i + 1]) ok.push_back(i);
    int diff = 0;
    for (int i = 0; i < n; i++) diff += A[i] != B[i];
    if (!diff) {
        cout << 1;
        return 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        vi nxt;
        int x = 0;
        for (int j : ok) {
            if (x > j) continue;
            x = j;
            for (; x < i; x++) {
                if (A[x] < A[x + 1]) break;
                diff += (A[x] == B[x]);
                diff += (A[x + 1] == B[x + 1]);
                swap(A[x], A[x + 1]);
                diff -= (A[x] == B[x]);
                diff -= (A[x + 1] == B[x + 1]);
                if (k-- && !diff) {
                    cout << 1;
                    return 0;
                } else if (k < 0) {
                    cout << 0;
                    return 0;
                }
            }
            for (int go = j; go < x; go++) {
                if (go > 0 && A[go - 1] > A[go]) nxt.push_back(go - 1);
            }
        }
        ok.swap(nxt);
    }

    cout << 0;
}
