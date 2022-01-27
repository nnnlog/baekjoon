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

int ans;

int vis[100001];
mpii prime;

int k, m;
void solve(int n) {
	if (n % 2 == 0 && n <= 6) return;
	if (n % 2 && !prime.count(n - 2)) return;
	while (n % m == 0) n /= m;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0 && prime.count(i) && prime.count(n / i)) {
			++ans;
			return;
		}
	}
}

vi chk(10);
int n;

void dfs(int sz) {
	if (sz == k) {
		solve(n);
		return;
	}
	for (int i = 0; i < 10; i++)
		if (!chk[i]) {
			chk[i] = 1;
			n *= 10;
			n += i;
			dfs(sz + 1);
			n /= 10;
			chk[i] = 0;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    prime[2] = 1;
	for (int i = 3; i <= 100000; i += 2) {
		if (vis[i]) continue;
		prime[i] = 1;
		for (int j = i; j <= 100000; j += i) vis[j] = 1;
	}

	cin >> k >> m;
	for (int i = 1; i <= 9; i++) n = i, chk[i] = 1, dfs(1), chk[i] = 0;
	cout << ans;
}
