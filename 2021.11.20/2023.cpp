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

bool is_prime(int a) {
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vector<set<int>> ans(n + 1);
	ans[1] = {2, 3, 5, 7};
	for (int i = 1; i < n; i++) {
		for (int j : ans[i]) {
			for (int k = 1; k <= 9; k++) {
				if (is_prime(j * 10 + k)) ans[i + 1].insert(j * 10 + k);
			}
		}
	}
	for (int i : ans[n]) cout << i << "\n";
}
