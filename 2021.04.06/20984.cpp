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
	vl vec(n + 1);
	for (int i = 1; i <= n; i++) vec[i] = getu();

	ll s = 1, e = n, ans = 0;
	while (s < e) {
		if (vec[s] < vec[s + 1]) ++s;
		else if (vec[e - 1] > vec[e]) --e;
		else {
			ll L = vec[s] + 1 - vec[s + 1], R = vec[e] + 1 - vec[e - 1];
			if (L <= R) ans += L, vec[e] -= L, ++s;
			else ans += R, vec[s] -= R, --e;
		}
	}

	cout << ans;
}
