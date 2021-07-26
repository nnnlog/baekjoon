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

void yes() {
	cout << "YES\n";
}
void no() {
	cout << "NO\n";
}
void yes(bool y) {
	if (y) yes();
	else no();
}

#include <sys/stat.h>
#include <sys/mman.h>
signed I[36];char*J=(char*)mmap(0,I[12],1,2,0,fstat(0,(struct stat*)I));
int getu(){int x=0;do x=x*10+*J-'0';while(*++J>='0');++J;return x;}
int geti(){bool e=*J=='-';J+=e;return(e?-1:1)*getu();}

vi UF;
int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}
void merge(int a, int b) {
	UF[find(a)] = UF[find(b)];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = getu();
	while (T--) {
		int n = getu();
		UF.assign(n, 0);
		iota(all(UF), 0);
		vi X(1e6, -1), Y(1e6, -1);
		for (int i = 0; i < n; i++) {
			int a, b;
			a = getu(), b = getu();
			if (X[--a] != -1) merge(i, X[a]);
			if (Y[--b] != -1) merge(i, Y[b]);
			X[a] = i;
			Y[b] = i;
		}
		set<int> s;
		for (int i = 0; i < n; i++) s.insert(find(i));
		int ans = s.size();
		cout << (ans / 2 + ans % 2) << "\n";
	}
}
