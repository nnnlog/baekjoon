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

	int n, k; cin >> n >> k;
	vi last(k);
	vi pos(n + 1);
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		pos[a] = i;
	}
	for (int i = 1; i <= n; i++) {
		int f = 0;
		for (auto &j : last) {
			if (j < pos[i]) {
				j = pos[i];
				f = 1;
				break;
			}
		}
		if (!f) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
