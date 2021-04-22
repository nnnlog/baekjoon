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
	vi vec(n);
	for (auto &i : vec) cin >> i;

	int l = vec[0], r = vec.back();
	if (l > r) swap(l, r);
	int diff = r - l;
	if (diff >= n - 2) {
		cout << r - n + 2;
		return 0;
	}
	int remain = n - 2 - diff;
	cout << l - (remain + 1) / 2;
}
