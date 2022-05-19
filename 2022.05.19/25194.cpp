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

    int n; cin >> n;
    vi vec(7 * 1001);
    vec[0] = 1;
    while (n--) {
        int a; cin >> a;
        a %= 7;
        for (int i = vec.size() - 1; i >= a; i--) {
            if (vec[i - a]) vec[i] |= vec[i - a];
        }
    }
    int ok = 0;
    for (int i = 4; i < vec.size(); i += 7) ok |= vec[i];
    cout << (ok ? "YES" : "NO");
}
