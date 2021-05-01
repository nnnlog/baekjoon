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

int table[21][200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> table[0][i];
	for (int k = 1; k <= 20; k++)
		for (int i = 1; i <= m; i++) table[k][i] = table[k - 1][table[k - 1][i]];
	int q;
	cin >> q;
	while (q--) {
		int n, x;
		cin >> n >> x;
		for (int i = 0; i <= 20; i++)
			if (n & (1 << i)) x = table[i][x];
		cout << x << "\n";
	}
}
