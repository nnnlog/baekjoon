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
	
	vi vec;
    int T; cin >> T;
    int g = 0;
    while (T--) {
        int a; cin >> a;
        g = gcd(g, a);
    }
        for (int i = 1; i * i <= g; i++) {
            if (g % i) continue;
            vec.push_back(i);
            vec.push_back(g / i);
        }
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    for (int i : vec) cout << i << "\n";
}
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
	
	vi vec;
    int T; cin >> T;
    int g = 0;
    while (T--) {
        int a; cin >> a;
        g = gcd(g, a);
    }
        for (int i = 1; i * i <= g; i++) {
            if (g % i) continue;
            vec.push_back(i);
            vec.push_back(g / i);
        }
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    for (int i : vec) cout << i << "\n";
}
