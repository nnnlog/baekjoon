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

void yes() {
	cout << "YES\n";
}
void no() {
	cout << "NO\n";
}
void yes(bool y) {
	if (y) yes();
	else no();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 1;
	cin >> T;
	while (T--) {
		int n; cin >> n;
        cout << "Pairs for " << n << ": ";
        for (int i = 1; i * 2 < n; i++) {
            if (i > 1) cout << ", ";
            cout << i << " " << n - i;
        }
        cout << "\n";
	}
}
