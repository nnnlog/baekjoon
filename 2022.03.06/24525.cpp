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

    string s; cin >> s;
    mpii idx;
    idx[0] = -1;
    int ans = -1;
    int S = 0, K = 0;
    int last = -1;
    for (int i = 0; i < s.size(); i++) {
        int chg = 0;
        if (s[i] == 'S') S++, chg = 1;
        if (s[i] == 'K') K++, chg = 1;
        if (chg) last = i;

        int curr = 2 * S - K;
        if (!idx.count(curr)) idx[curr] = i;//, cout << "regi " << i << " " << S << " " << K << " " << i + 1 << "\n";
//        else if (S >= 1 && K >= 2) ans = max(ans, i - idx[curr]), cout << "solv " << i << " " << S << " " << K << " " << idx[curr] << "\n";
        else if (idx[curr] != last) ans = max(ans, i - idx[curr]);//, cout << "solv " << i << " " << S << " " << K << " " << idx[curr] << "\n";

        //if (s[i] == 'S' || s[i] == 'K') go = i + 1;
    }
    cout << ans;
}
