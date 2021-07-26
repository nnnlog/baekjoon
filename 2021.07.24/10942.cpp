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

int chk[2001][2001], n, vec[2001];
void init(int l, int r) {
	if (l < 1 || r > n) return;
	if (chk[l][r]) return;
	chk[l][r] = 1;
	if (l > 1 && r < n && vec[l - 1] == vec[r + 1]) init(l - 1, r + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> vec[i];
	for (int i = 1; i < n; i++) if (vec[i] == vec[i + 1]) init(i, i + 1);
	for (int i = 1; i <= n; i++) init(i, i);
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		cout << chk[l][r] << "\n";
	}
}
