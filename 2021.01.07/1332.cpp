#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int solve(int a, int b) {
	if (a > b) swap(a, b);
	b -= a;
	int ans = 1;
	--a;
	if (a % 2) ans++;
	ans += a / 2;

	if (b % 2) ans++;
	ans += b / 2;
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, v; cin >> n >> v;
	vi vec(n + 1);

	for (int i = 1; i <= n; i++) cin >> vec[i];

	int ans = n;
	//홀홀
	int mx = -1, mn = 1e9, mx_id = -1, mn_id = -1;
	for (int i = 1; i <= n; i += 2) {
		if (mx < vec[i]) {
			mx = vec[i];
			mx_id = i;
		}
		if (mn > vec[i]) {
			mn = vec[i];
			mn_id = i;
		}
		if (mx - mn >= v) {
			ans = min(ans, solve(mx_id, mn_id));
			//break;
		}
	}
	//홀짝
	mx = -1, mn = 1e9, mx_id = -1, mn_id = -1;
	for (int i = 1; i <= n; i += 2) {
		if (mx < vec[i]) {
			mx = vec[i];
			mx_id = i;
		}
		if (mn > vec[i]) {
			mn = vec[i];
			mn_id = i;
		}
		if (i < n && abs(mn - vec[i + 1]) >= v) {
			ans = min(ans, solve(i + 1, mn_id));
			//break;
		}
		if (i < n && abs(mx - vec[i + 1]) >= v) {
			ans = min(ans, solve(mx_id, i + 1));
			//break;
		}
	}
	//짝짝
	mx = -1, mn = 1e9, mx_id = -1, mn_id = -1;
	for (int i = 2; i <= n; i += 2) {
		if (mx < vec[i]) {
			mx = vec[i];
			mx_id = i;
		}
		if (mn > vec[i]) {
			mn = vec[i];
			mn_id = i;
		}
		if (mx - mn >= v) {
			ans = min(ans, solve(mx_id, mn_id));
			//break;
		}
	}
	//짝홀
	mx = -1, mn = 1e9, mx_id = -1, mn_id = -1;
	for (int i = 2; i <= n; i += 2) {
		if (mx < vec[i]) {
			mx = vec[i];
			mx_id = i;
		}
		if (mn > vec[i]) {
			mn = vec[i];
			mn_id = i;
		}
		if (abs(mn - vec[i - 1]) >= v) {
			ans = min(ans, solve(i - 1, mn_id));
			//break;
		}
		if (abs(mx - vec[i - 1]) >= v) {
			ans = min(ans, solve(mx_id, i - 1));
			//break;
		}
	}
	if (abs(mx - vec[n]) >= v) {
		ans = min(ans, solve(mx_id, n));
	}
	if (abs(mn - vec[n]) >= v) {
		ans = min(ans, solve(n, mn_id));
	}

	cout << ans;
}
