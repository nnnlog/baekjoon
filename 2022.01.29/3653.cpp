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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vi idx(n + 1);
        int back = 1;
        ordered_set S;
        for (int i = n; i >= 1; i--) S.insert(back), idx[i] = back++;
        while (m--) {
            int a; cin >> a;
            cout << S.size() - 1 - S.order_of_key(idx[a]) << " ";
            S.erase(idx[a]);
            S.insert(idx[a] = back++);
        }
        cout << "\n";
    }
}
