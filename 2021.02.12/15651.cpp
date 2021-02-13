#include <bits/stdc++.h>
#include <unistd.h>

#define all(v) v.begin(), v.end()

using namespace std;

namespace io {
	const int is = 1 << 17, os = 1 << 10;
	char ib[is], *ip = ib;
	char ob[os + 16], *op = ob;

	inline char read() {
		if(ib + is == ip) syscall(0, 0, ip = ib, is);
		return *ip;
	}

	inline int readInt() {
		int n = 0;
		while (read() <= ' ') ip++;
		while (read() >= '0') n = (n * 10) + (*ip++ & 15);
		return n;
	}

	inline void flush() {
		syscall(1, 1, op = ob, op - ob);
	}
	struct f {
		~f() {
			flush();
		}
	} flusher;

	inline void writeInt(int n) {
		char temp[16], *t = temp;
		do *t++ = n % 10 | 48; while(n /= 10);
		do *op++ = *--t; while(t != temp);
		*op++ = ' ';
		if(op >= ob + os) flush();
	}

	inline void writeln() {
		*op++ = '\n';
		if(op >= ob + os) flush();
	}
}

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

int n, m;
vi v;
void solve(int i) {
	if (i == m) {
		for (const auto &k : v) io::writeInt(k);
		io::writeln();
		return;
	}
	++i;
	for (int j = 1; j <= n; j++) v.emplace_back(j), solve(i), v.pop_back();
}

int main() {
	cin >> n >> m;
	solve(0);
}
