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

string max(string a, string b) {
	if (a.size() != b.size()) return a.size() > b.size() ? a : b;
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string A, B;
	getline(cin, A);
	getline(cin, B);

	vector<vector<string>> dp(A.size() + 1, vector<string>(B.size() + 1));
	for (int i = 1; i <= A.size(); i++)
		for (int j = 1; j <= B.size(); j++) {
			if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + A[i - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	cout << dp.back().back().size() << "\n" << dp.back().back();
}
