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
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < 2 * (n - 1); i++) cnt += s[i] == 'I' && s[i + 1] == 'O';
	int ans = 0;
	for (int i = 0; i < m - 2 * n; i++) {
		cnt += s[i + 2 * (n - 1)] == 'I' && s[i + 2 * (n - 1) + 1] == 'O';
		ans += cnt == n && s[i + 2 * n] == 'I';
		//cout << i << " " << cnt << "\n";
		cnt -= s[i] == 'I' && s[i + 1] == 'O';
	}
	cout << ans;
}
