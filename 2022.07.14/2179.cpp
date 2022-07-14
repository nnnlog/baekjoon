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

    int n;
    cin >> n;

    int ans = 0, idx;
    pair<string, string> pss;

    unordered_map<string, int> ok;
    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vec[i] = s;

        for (int j = 1; j <= s.size(); j++) {
            string t = s.substr(0, j);
            if (!ok.count(t)) ok[t] = i;
            else if (ok[t] >= 0) {
                if (ans < t.size() || (ans == t.size() && idx > ok[t])) ans = t.size(), idx = ok[t], pss = {vec[ok[t]], s}, ok[t] = -1;
            }
        }
    }

    cout << pss.first << "\n" << pss.second;
}
