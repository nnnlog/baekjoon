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
	
	int n, m; cin >> n >> m;
    map<int, int> A, B;
    while (n--) {
        int a; cin >> a;
        A[a] = 1;
    }
    while (m--) {
        int a; cin >> a;
        B[a] = 1;
    }
    vi ans;
    for (const auto &[a, _] : A) if (!B[a]) ans.push_back(a);
    cout << ans.size() << "\n";
    for (const auto &a : ans) cout << a << "\n";
}
