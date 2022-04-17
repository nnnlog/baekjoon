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
	
	int k; cin >> k;
    int n; cin >> n;
    int curr = 0;
    --k;
    while (n--) {
        int a; cin >> a;
        char c; cin >> c;
        
        curr += a;
        if (curr >= 3 * 60 + 30) {
            cout << k + 1;
            return 0;
        }
        if (c == 'T') {
            k++;
            k %= 8;
        }
    }
}
