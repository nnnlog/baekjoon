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

	int n = getu();
	vi vec(n + 1);
	for (auto &i : vec | drop(1)) i = getu();

	vi L(n + 1, -1e9), R(n + 1, -1e9);
	int mn = 1e9, mx = -1e9;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, vec[i]);
		if (mn != 1e9) L[i] = mx - mn;
		if (mn > vec[i]) {
			mn = vec[i];
			mx = -1e9;
		}
		if (mx != -1e9) L[i] = mx - mn;
	}
	mn = 1e9, mx = -1e9;
	for (int i = n; i >= 1; i--) {
		mn = min(mn, vec[i]);
		if (mx != -1e9) R[i] = mx - mn;
		if (mx < vec[i]) {
			mx = vec[i];
			mn = 1e9;
		}
		if (mn != 1e9) R[i] = mx - mn;
	}

	int ans = -1e9;
	for (int i = 1; i < n; i++) ans = max(ans, L[i] + R[i + 1]);
	cout << ans;
}
