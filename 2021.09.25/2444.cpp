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

	int n, i = 1; cin >> n;
	for (; i < 2 * n; i += 2) {
		for (int j = 1; j < n - i / 2; j++) cout << ' ';
		for (int j = 0; j < i; j++) cout << '*';
		cout << '\n';
	}
	for (i -= 4; i >= 1; i -= 2) {
		for (int j = 1; j < n - i / 2; j++) cout << ' ';
		for (int j = 0; j < i; j++) cout << '*';
		cout << '\n';
	}
}