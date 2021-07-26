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

	vi vec(191230, 1);
	for (int i = 2; i < vec.size(); i++) vec[i] = (vec[i - 1] + vec[i - 2]) % (int)(1e9 + 7);

	int T; cin >> T;
	while (T--) {
		int a; cin >> a;
		cout << vec[a] << "\n";
	}
}
