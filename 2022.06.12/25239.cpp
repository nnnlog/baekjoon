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

    char t;
    int H, M;
    cin >> H >> t >> M;

    vi vec(6);
    for (int &i : vec) cin >> i;

    int T; cin >> T;
    while (T--) {
        cin.ignore(100, ' ');
        string s; cin >> s;

        if (s == "^") {
            vec[H / 2] = 0;
        } else if (s.find("MIN") != string::npos) {
            stringstream ss(s);
            int plus; ss >> plus;
            M += plus;
            if (M >= 60) ++H, M -= 60;
            if (H >= 12) H -= 12;
        } else {
            stringstream ss(s);
            int plus; ss >> plus;
            H += plus;
            if (H >= 12) H -= 12;
        }
    }

    cout << min(100, reduce(all(vec)));
}
