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

	int t; cin >> t;
	for (int i = t / 300; i >= 0; --i) {
		for (int j = (t - i * 300) / 60; j >= 0; --j) {
			int r = t - i * 300 - j * 60;
			if (r % 10 == 0) {
				cout << i << " " << j << " " << r / 10;
				return 0;
			}
		}
	}
	cout << -1;
}
