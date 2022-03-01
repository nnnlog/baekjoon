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
    sort(all(vec));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0, o = vec[i];
        for (; i < n; i++) {
            if (o != vec[i]) break;
            else cnt++;
        }
        i--;
        ans = max(ans, cnt);
    }
    vec.erase(unique(all(vec)), vec.end());
    n = vec.size();
    vector<vi> vis(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (vis[i][j]) continue;
            int cnt = 1;
            int prv = j;
            for (int k = vec[i];; k += vec[i] - vec[j]) {
                int idx = lower_bound(all(vec), k) - vec.begin();
                if (idx == n || vec[idx] != k) break;
                vis[idx][prv] = 1;
                prv = idx;
                cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;
}
