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

int n, k, diff;
vi A, B;

void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    vi tmp(r - l + 1);
    merge(A.begin() + l, A.begin() + mid + 1, A.begin() + mid + 1, A.begin() + r + 1, tmp.begin());
    for (int i = l; i <= r; i++) {
        diff += A[i] == B[i];
        A[i] = tmp[i - l];
        diff -= A[i] == B[i];
        if (!diff) {
            cout << 1;
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    A.resize(n);
    B.resize(n);
    for (int &i : A) cin >> i;
    for (int &i : B) cin >> i;
    for (int i = 0; i < n; i++) diff += A[i] != B[i];
    if (!diff) return (cout << 1), 0;
    merge_sort(0, n - 1);
    cout << 0;
}
