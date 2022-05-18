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
	string s; cin >> s;

	int cnt = 0;
	for (char c : s) cnt += c == 'C';

	if (!cnt) return cout << 0, 0;

	for (int i = 1; i <= n; i++) {
		if (cnt / i + (cnt % i > 0) - 1 + cnt <= n) return cout << i, 0;
	}
}
