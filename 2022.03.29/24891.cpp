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

int l, n;
string ans;

void check(vector<string> ok) {
    string final;
    for (int i = 0; i < l; i++) {
        string tmp;
        for (int j = 0; j < l; j++) tmp.push_back(ok[j][i]);
        if (ok[i] != tmp) return;
        final += ok[i];
    }
    if (ans.empty()) ans = final;
    else ans = min(ans, final);
}

vector<string> ok;
vector<string> vec;
void dfs(int i) {
    if (ok.size() == l) {
        do {
            check(ok);
        } while (next_permutation(all(ok)));
        return;
    }
    if (i == vec.size()) return;
    dfs(i + 1);

    ok.push_back(vec[i]);
    dfs(i + 1);
    ok.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> l >> n;
    vec.resize(n);
    for (auto &s : vec) cin >> s;
    sort(all(vec));

    dfs(0);

    if (ans.empty()) cout << "NONE";
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if ((i + 1) % l == 0) cout << "\n";
        }
    }
}
