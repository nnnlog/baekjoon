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
    int n = s.size();
    string ans;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n - 1; j++) {
            string a = s.substr(0, i + 1);
            string b = s.substr(i + 1, j - i);
            string c = s.substr(j + 1, n - j);

            reverse(all(a)), reverse(all(b)), reverse(all(c));

            string tmp = a + b + c;
            if (ans.empty()) ans = tmp;
            else ans = min(ans, tmp);
        }
    cout << ans;
}
