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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q; cin >> n >> q;
	vi vec(n);
	for (auto &i : vec) cin >> i;
	vec.push_back(0);
	sort(all(vec));
	for (int i = 1; i <= n; i++) vec[i] += vec[i - 1];
	while (q--) {
		int a, b; cin >> a >> b;
		cout << vec[b] - vec[a - 1] << "\n";
	}
}
