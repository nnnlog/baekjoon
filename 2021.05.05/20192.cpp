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

	int n = getu();
	vi vec(n);
	for (auto &i : vec) i = getu();
	if (vec.size() <= 1) {
		cout << 0;
		return 0;
	}
	vec.erase(unique(all(vec)), vec.end());
	int ans = vec[vec.size() - 2] < vec[vec.size() - 1], status = 0, f = 1;
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i - 1] < vec[i]) {
			status = 0;
		} else if (vec[i - 1] > vec[i]) {
			if (!status) ++ans;
			f = 0;
			status = 1;
		}
	}
	if (f) cout << 0;
	else cout << (int)ceil(log2(ans)) + 1;
}
