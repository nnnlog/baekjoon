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
        int ans = 0;
        while (n--) {
            char a, b; cin >> a >> b;
            if (a == b) continue;
            if (a == 'R') {
                if (b == 'S') ans++;
                else ans--;
            } else if (a == 'S') {
                if (b == 'R') ans--;
                else ans++;
            } else { // P
                if (b == 'S') ans--;
                else ans++;
            }
        }
        if (!ans) cout << "TIE\n";
        else if (ans > 0) cout << "Player 1\n";
        else cout << "Player 2\n";
    }
}
