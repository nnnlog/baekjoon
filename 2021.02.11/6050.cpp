#include <bits/stdc++.h>
#include <unistd.h>

#define all(v) v.begin(), v.end()

using namespace std;

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
		*op++ = '\n';
		if(op >= ob + os) flush();
	}
}

int main() {
	int n = io::readInt();
	vl vec(n + 1);
	for (int i = 1; i <= n; i++) vec[i] = io::readInt();
	ll l = 1, l_backup = 1, backup_sz = 1e18, down = 0;
	vec[0] = 1e18;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (down && vec[i - 1] < vec[i]) { //산의 시작과 종료
			//cout << l << " " << i << "\n";
			ans = max(i - l, ans);
			l = l_backup;
			//cout << "start from " << l << "\n";
			down = 0;
		}
		if (vec[i - 1] > vec[i]) down = 1;

		if (vec[i] != backup_sz) {
			backup_sz = vec[i];
			l_backup = i;
		}
		//cout << "bk " << backup_sz << " " << l_backup << "\n";
	}

	ans = max(n + 1 - l, ans);
	cout << ans;
}
