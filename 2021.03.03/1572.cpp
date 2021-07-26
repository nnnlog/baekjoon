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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<pii, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#include <sys/stat.h>
#include <sys/mman.h>

signed I[36];
char *J = (char *) mmap(0, I[12], 1, 2, 0, fstat(0, (struct stat *) I));

int getu() {
	int x = 0;
	do x = x * 10 + *J - '0'; while (*++J >= '0');
	++J;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	n = getu();
	k = getu();
	ordered_set s;
	queue<int> q;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i > k) s.erase(pii(q.front(), i - k)), q.pop();
		int a = getu();
		if (i <= n - k) q.push(a);
		s.insert({a, i});
		if (i >= k) ans += s.find_by_order((k - 1) / 2)->first;
	}

	cout << ans;
}
