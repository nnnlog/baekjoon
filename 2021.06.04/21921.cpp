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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x, sum = 0; cin >> n >> x;
	int ans = 0, sz = 0;
	queue<int> q;
	while (n--) {
		int a; cin >> a;
		sum += a;
		if (q.size() == x) sum -= q.front(), q.pop();
		q.push(a);
		if (sum > ans) ans = sum, sz = 1;
		else if (sum == ans) ++sz;
	}
	if (!ans) cout << "SAD";
	else cout << ans << "\n" << sz;
}
