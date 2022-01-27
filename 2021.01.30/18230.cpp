#include bitsstdc++.h

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pairint, int pii;
typedef pairll, ll pll;
typedef vectorint vi;
typedef vectorll vl;
typedef vectorpii vpii;
typedef vectorpll vpll;
typedef unordered_mapint, int mpii;

int main() {
	ios_basesync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, a, b, ans = 0; cin  n  a  b;
	vl A(a), B(b);
	for (auto &i  A) cin  i;
	for (auto &i  B) cin  i;
	sort(all(A), greater());
	if (n % 2) {
		ans += A[0];
		A.erase(A.begin());
		--n;
	}
	for (int i = 0; i + 1  A.size(); i += 2) B.push_back(A[i] + A[i + 1]);
	n = 2;
	sort(all(B), greater());
	for (int i = 0; i  n; i++) ans += B[i];
	cout  ans;
}
