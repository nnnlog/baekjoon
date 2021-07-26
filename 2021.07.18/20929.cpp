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

int n;
int query(char c, int k) {
	if (k == 0) return 0;
	if (k == n + 1) return 1e9;
	cout << "? " << c << " " << k << endl;
	int a; cin >> a;
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		int A = query('A', mid);
		int B = query('B', n - mid);
		if (A > B) r = mid;
		else l = mid + 1;
	}
	int mid = ((l + r) >> 1);
	int A = query('A', mid);
	int B = query('B', n - mid + 1);
	cout << "! " << min(A, B);
}
