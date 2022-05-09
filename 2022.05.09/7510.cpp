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
    for (int i = 1; i <= T; i++) {
        vl v(3);
        for (auto &i : v) cin >> i;
        sort(all(v));
        cout << "Scenario #" << i << ":\n" << (v[0] * v[0] + v[1] * v[1] == v[2] * v[2] ? "yes" : "no") << "\n\n";
    }
}
