#include <bits/stdc++.h>

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b, d, n, ans = 1, sum = 0; cin >> a >> b >> d >> n;
	vi cnt(n + 1);
	cnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i >= b) sum -= cnt[i - b] - 1000, sum %= 1000;
		if (i >= a) sum += cnt[i - a], sum %= 1000;
		cnt[i] = sum;
		ans += cnt[i];
		if (i >= d) ans -= cnt[i - d] - 1000, sum %= 1000;
	}
	cout << ans % 1000;
}
