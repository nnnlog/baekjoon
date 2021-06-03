#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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

int n, d;
ll ans = 0;

vl T, V;

ll C(int i, int j) {
	//if (j - i > d) return -1;
	return (j - i) * T[j] + V[i];
}

void dnc(int l, int r, int s, int e) {
	if (l > r) return;
	int mid = (l + r) >> 1;
	int k = max(s, mid - d);
	ll mx = C(k, mid);
	for (int i = k; i <= min(mid, e); i++) {
		ll nxt = C(i, mid);
		if (mx < nxt) mx = nxt, k = i;
	}
	ans = max(ans, mx);
	dnc(l, mid - 1, s, k);
	dnc(mid + 1, r, k, e);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	 cin >> n >> d;
	 V.resize(n + 1), T.resize(n + 1);
	 for (auto &i : T | drop(1)) cin >> i;
	 for (auto &i : V | drop(1)) cin >> i;
	 dnc(1, n, 1, n);
	 cout << ans;
}
