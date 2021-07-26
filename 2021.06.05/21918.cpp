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
	vi vec(n);
	for (auto &i : vec) cin >> i;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		--b;
		if (a == 1) vec[b] = c;
		--c;
		if (a == 2) for (int i = b; i <= c; i++) vec[i] = !vec[i];
		if (a == 3) fill(vec.begin() + b, vec.begin() + c + 1, 0);
		if (a == 4) fill(vec.begin() + b, vec.begin() + c + 1, 1);
	}
	for (int i : vec) cout << i << " ";
}
