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
	int prv = -1e9, c = 1, f = 1;
	while (n--) {
		int a; cin >> a;
		if (prv == a) {
			f = 0;
			break;
		}
		if ((prv < a) ^ (c)) {
			if (c) c = 0;
			else {
				f = 0;
				break;
			}
		}
		prv = a;
	}
	cout << (f ? "YES" : "NO");
}
