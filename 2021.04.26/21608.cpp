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

int chk[22][22];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll ans = 0;
	int n; cin >> n;
	unordered_map<int, mpii> vec;
	for (int k = 0; k < n * n; k++) {
		int a; cin >> a;
		mpii &f = vec[a];
		for (int l = 0; l < 4; l++) {
			int b; cin >> b;
			f[b] = 1;
		}

		int like = -1, emp = -1;
		pii ok;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (chk[i][j]) continue;
				int tl = 0, te = 0;
				for (const auto &[dx, dy] : vpii{
						{-1, 0},
						{1, 0},
						{0, 1},
						{0, -1}
				}) {
					int x = dx + i, y = dy + j;
					if (x < 1 || y < 1 || x > n || y > n) continue;
					if (!chk[x][y]) ++te;
					else if (f.count(chk[x][y])) ++tl;
				}
				if (tl > like) like = tl, emp = te, ok = {i, j};
				else if (tl == like && te > emp) emp = te, ok = {i, j};
			}

		chk[ok.first][ok.second] = a;
	}


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int c = 0;
			for (const auto &[dx, dy] : vpii{
					{-1, 0},
					{1,  0},
					{0,  1},
					{0,  -1}
			}) {
				int x = dx + i, y = dy + j;
				if (x < 1 || y < 1 || x > n || y > n) continue;
				if (vec[chk[i][j]].count(chk[x][y])) ++c;
			}
			if (c) ans += pow(10, c - 1);
		}

	cout << ans;
}
