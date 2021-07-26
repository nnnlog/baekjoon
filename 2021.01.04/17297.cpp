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

vector<string> dp = {"", "Messi", "Messi Gimossi"};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	dp.resize(1e4);
	//for (int i = 3; i <= 10; i++) cout << setfill('0') << setw(2) << i << " " << (dp[i] = dp[i - 1] + " " + dp[i - 2]) << "\n";
	ll n; cin >> n;
	while (n > dp[2].size()) {
		ll a = dp[2].size(), b = dp[1].size();
		for (int i = 3; ; i++) {
			ll curr = a + b + 1;
			//cout << i << " " << curr << "\n";
			if (curr >= n) {
				//cout << i << " ";
				n -= a + 1;
				break;
			}
			b = a;
			a = curr;
		}
		//cout << n << "\n";
	}

	--n;
	if (n < 0 || dp[2][n] == ' ') cout << "Messi Messi Gimossi";
	else cout << dp[2][n];
}
