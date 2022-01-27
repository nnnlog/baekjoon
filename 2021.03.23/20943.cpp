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

pii normalize(int a, int b) {
	int g = gcd(abs(a), abs(b));
	a /= g;
	b /= g;
	if (a * b > 0) a = abs(a), b = abs(b);
	else a = -abs(a), b = abs(b);
	return {a, b};
}

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1,T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);
		return h1 ^ h2;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n = geti();
	ll ans = n * (n - 1) / 2;
	unordered_map<pii, unordered_map<pii, int, pair_hash>, pair_hash> cnt;
	while (n--) {
		int a, b, c;
		a = geti();
		b = geti();
		c = geti();

		cnt[normalize(a, b)][normalize(b, c)]++;
	}

	for (const auto &[a, b] : cnt) ans -= b.size() * (b.size() - 1) / 2;

	cout << ans;
}
