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
	
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        unordered_map<string, int> mp;
        while (n--) {
            string a, b; cin >> a >> b;
            mp[b]++;
        }
        int ans = 1;
        for (const auto &[_, v] : mp) ans *= (v + 1);
        cout << --ans << "\n";
    }
}
