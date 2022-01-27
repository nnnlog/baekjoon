#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int garo[9][10], sero[9][10], table[3][3][10], mp[9][9];
string ans;

void solve(int n) {
	if (n == 81) {
		string res;
		for (auto &i : mp) {
			for (int j : i) res.push_back(j + '0'), res.push_back(' ');
			res += "\n";
		}
		cout << res << endl;
		exit(0);
	}

	int i = n / 9, j = n % 9;
	if (mp[i][j]) solve(n + 1);
	else
		for (int k = 1; k <= 9; k++) {
			if (garo[i][k] || sero[j][k] || table[i / 3][j / 3][k]) continue;
			garo[i][k] = sero[j][k] = table[i / 3][j / 3][k] = 1;
			mp[i][j] = k;
			//cout << cnt << " " << i << " " << j << endl;
			solve(n + 1);
			garo[i][k] = sero[j][k] = table[i / 3][j / 3][k] = 0;
			mp[i][j] = 0;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			char c;
			cin >> c;
			int k = c - '0';
			garo[i][k] = sero[j][k] = table[i / 3][j / 3][k] = 1;
			mp[i][j] = k;
		}

	solve(0);
	cout << ans;
}
