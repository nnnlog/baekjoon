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
	while (T--) {
		int a; cin >> a;
		--a;
		a %= 28;
		++a;
		if (a >= 16) a = 15 - a % 15;
		for (int i = 3; i >= 0; --i)
			cout << ((a & (1 << i)) ? "딸기" : "V");
		cout << "\n";
	}
}
