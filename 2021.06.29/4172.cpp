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

	const int MX = 1000000;
	vi dp(MX + 1);
	dp[0] = 1;
	for (int i = 1; i <= MX; i++) dp[i] = (dp[i - sqrt(i)] + dp[log(i)] + dp[i * sin(i) * sin(i)]) % MX;
	while (1) {
		int a; cin >> a;
		if (a == -1) return 0;
		cout << dp[a] << "\n";
	}
}
