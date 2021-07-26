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

	int n, k, q, m; cin >> n >> k >> q >> m;
	vi is_sleep(n + 3), chk(n + 3, 1);
	chk[0] = chk[1] = chk[2] = 0;
	while (k--) {
		int a; cin >> a;
		is_sleep[a] = 1;
	}
	while (q--) {
		int a; cin >> a;
		if (!is_sleep[a]) for (int i = a; i <= n + 2; i += a) if (!is_sleep[i]) chk[i] = 0;
	}
	for (int i = 1; i <= n + 2; i++) chk[i] += chk[i - 1];
	while (m--) {
		int s, e; cin >> s >> e;
		cout << chk[e] - chk[s - 1] << "\n";
	}
}
