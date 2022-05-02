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
	
	for (int i = 1;; i++) {
        
        int n; cin >> n;
        if (!n) return 0;
        int n1 = n * 3;
        int n2 = (n1 + 1) / 2;
        int n3 = n2 * 3;
        int n4 = n3 / 9;
        
        cout << i << ". " << (n1 % 2 ? "odd" : "even") << " " << n4 << "\n";
    }
}
