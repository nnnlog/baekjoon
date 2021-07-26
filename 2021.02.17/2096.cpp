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

int mp[100001][3];
vi prv(3);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++) cin >> mp[i][j];

	for (int i = 1; i <= n; i++) {
		vi nxt(3);
		for (int j = 0; j < 3; j++) {
			for (int d = -1; d <= 1; d++) {
				int x = j + d;
				if (x < 0 || x >= 3) continue;
				nxt[j] = max(nxt[j], prv[x] + mp[i][j]);
			}
		}
		prv = nxt;
	}
	cout << *max_element(all(prv)) << " ";
	prv.assign(3, 0);
	for (int i = 1; i <= n; i++) {
		vi nxt(3, 1e9);
		for (int j = 0; j < 3; j++) {
			for (int d = -1; d <= 1; d++) {
				int x = j + d;
				if (x < 0 || x >= 3) continue;
				nxt[j] = min(nxt[j], prv[x] + mp[i][j]);
			}
		}
		prv = nxt;
	}

	cout << *min_element(all(prv));
}
