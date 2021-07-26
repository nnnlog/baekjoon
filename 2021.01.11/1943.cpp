#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 3;
	while (T--) {
		int n, sum = 0;
		cin >> n;
		vpii vec(n);
		vi dp(50001);
		for (auto &[a, b] : vec) cin >> a >> b;

		int mx = 0;
		dp[0] = 1;
		for (const auto &[a, b] : vec) {
			for (int j = min((int) dp.size() - 1, mx + a); j >= a; j--) {
				if (dp[j - a]) {
					for (int i = 0; i < b && j + a * i < dp.size(); i++) dp[j + a * i] = 1;
					mx = max(mx, j + (b - 1) * a);
				}
			}
			sum += a * b;
		}

		cout << (!(sum % 2) && dp[sum / 2]) << "\n";
	}
}
