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
    vi active(n + 1, 1);
    vector<vi> in(n + 1);
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        if (s == "cancel") {
            int a; cin >> a;
            in[a].push_back(i);
        }
    }
    vi ans;
    for (int i = n; i >= 1; --i) {
        for (int j : in[i]) if (active[j]) {
            active[i] = 0;
            break;
        }
        if (active[i]) ans.push_back(i);
    }
    reverse(all(ans));
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
}
