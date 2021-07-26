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

#include <sys/stat.h>
#include <sys/mman.h>
signed I[36];char*J=(char*)mmap(0,I[12],1,2,0,fstat(0,(struct stat*)I));
int getu(){int x=0;do x=x*10+*J-'0';while(*++J>='0');++J;return x;}
int geti(){bool e=*J=='-';J+=e;return(e?-1:1)*getu();}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k = getu();

	vi vec(k);
	ll ans = 1e18, sv = 0;
	for (auto &i : vec) i = getu(), sv += i / k, i %= k;

	sort(all(vec));
	for (int i = 0; i < k; i++) {
		ll t = i;
		t += vec.end() - upper_bound(all(vec), i);
		ans = min(ans, t);
	}

	cout << sv + ans;
}
