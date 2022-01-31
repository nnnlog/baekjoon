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

    int q; cin >> q;
    int n, m; cin >> n >> m;
    vi A(n), B(m);
    for (int &i : A) cin >> i;
    for (int &i : B) cin >> i;
    mpii cnt;
    cnt[0] = 1;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = i; j < m + i - (i != 0); j++) {
            sum += B[j % m];
            if (sum > q) break;
            cnt[sum]++;
        }
    }

    ll ans = cnt[q];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n + i - (i != 0); j++) {
            sum += A[j % n];
            if (sum > q) break;
            if (cnt.count(q - sum)) ans += cnt[q - sum];
        }
    }

    cout << ans;
}
