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

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
	std::ostream::sentry s( dest );
	if ( s ) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[ 128 ];
		char* d = std::end( buffer );
		do
		{
			-- d;
			*d = "0123456789"[ tmp % 10 ];
			tmp /= 10;
		} while ( tmp != 0 );
		if ( value < 0 ) {
			-- d;
			*d = '-';
		}
		int len = std::end( buffer ) - d;
		if ( dest.rdbuf()->sputn( d, len ) != len ) {
			dest.setstate( std::ios_base::badbit );
		}
	}
	return dest;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, q; cin >> n >> q;
	__int128 idx = 0, ans = 1e36;
	for (int i = 1; i <= n; i++) {
		ll p, k, c;
		cin >> p >> k >> c;
		__int128 d = q / k;
		if (q % k == 0) --d;
		__int128 t = p + (__int128)d * (d + 1) * c / 2;
		if (t < ans) {
			ans = t;
			idx = i;
		}
	}
	cout << idx << " " << ans;
}
