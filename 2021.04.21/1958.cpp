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

int dp[101][101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string A, B, C; cin >> A >> B >> C;
	int ans = 0;
	for (int i = 1; i <= A.size(); i++)
		for (int j = 1; j <= B.size(); j++)
			for (int k = 1; k <= C.size(); k++) {
				dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
			}
	cout << dp[A.size()][B.size()][C.size()];
}
