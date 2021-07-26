#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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

#include <sys/stat.h>
#include <sys/mman.h>
signed I[36];char*J=(char*)mmap(0,I[12],1,2,0,fstat(0,(struct stat*)I));
int getu(){int x=0;do x=x*10+*J-'0';while(*++J>='0');++J;return x;}
int geti(){bool e=*J=='-';J+=e;return(e?-1:1)*getu();}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, k;
	n = getu();
	k = getu();
	vl vec(n + 1), sum(n + 1), dp(n + 1);
	for (auto &i : vec | drop(1)) i = getu();
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + vec[i];
	for (int i = 1; i <= n; i++) {
		ll s = i, e = n;
		while (s < e) {
			ll mid = (s + e) >> 1;
			if (sum[mid] - sum[i - 1] >= k) e = mid;
			else s = mid + 1;
		}
		ll mid = (s + e) >> 1;
		//if (sum[i] - sum[mid])
		dp[i] = max(dp[i], dp[i - 1]);
		dp[mid] = max(dp[mid], dp[i - 1] + max(0LL, sum[mid] - sum[i - 1] - k));
		//cout << i << " " << mid << " " << dp[mid] << "\n";
	}
	cout << dp[n];
}
