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
 
	int n; cin >> n;
 
	vi vec(n + 1);
	for (int i = 1; i <= n; i++) cin >> vec[i];
 
	vi sum(n + 1);
	for (int i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + (vec[i - 1] > vec[i]);
	}
 
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		int ans = 1 + sum[r] - sum[l];
		if (ans == 1) cout << 1;
		else if (ans == 2 && vec[l] > vec[r]) cout << 2;
		else cout << 3;
		cout << "\n";
	}
}
