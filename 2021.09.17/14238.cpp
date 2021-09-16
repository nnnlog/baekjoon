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

string dp[51][51][51][2][3];
int a, b, c;

int check(const string &s, int t) {
	if (s.empty()) return 0;
	if (!t) return s.back() != 'B';
	else return s.size() < 2 || s[s.size() - 2] != 'C';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	for (char x: s) a += x == 'A', b += x == 'B', c += x == 'C';
	dp[0][0][0][0][0] = "_";
	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++)
			for (int k = 0; k <= c; k++) {
				for (int x = -1; x < 1; x++)
					for (int y = -1; y < 2; y++)
						if (i && !dp[i - 1][j][k][x + 1][y + 1].empty()) dp[i][j][k][max(0, x)][max(0, y)] = dp[i - 1][j][k][x + 1][y + 1] + "A";
				for (int y = -1; y < 2; y++)
					if (j && !dp[i][j - 1][k][0][y + 1].empty()) dp[i][j][k][1][max(0, y)] = dp[i][j - 1][k][0][y + 1] + "B";
				for (int x = -1; x < 1; x++)
					if (k && !dp[i][j][k - 1][x + 1][0].empty()) dp[i][j][k][max(0, x)][2] = dp[i][j][k - 1][x + 1][0] + "C";
			}

	string ans = "";
	for (auto &v : dp[a][b][c]) for (auto &s : v) ans = max(ans, s);
	if (ans.empty()) cout << -1;
	else cout << ans.substr(1);
}
