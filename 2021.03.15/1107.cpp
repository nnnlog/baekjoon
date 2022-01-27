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

int n, ans = 1e9;
vi chk(10);

void solve(int a, int d) {
	if (7 <= d) return;
	//cout << a << "\n";
	ans = min(ans, d + abs(a - n));
	for (int i = 0; i < 10; i++) {
		if (!chk[i]) solve(a * 10 + i, d + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	int m;
	cin >> m;
	while (m--) {
		int a;
		cin >> a;
		chk[a] = 1;
	}
	for (int i = 0; i < 10; i++) if (!chk[i]) solve(i, 1);
	ans = min(ans, abs(100 - n));
	cout << ans;
}
