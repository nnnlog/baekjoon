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

	int n, k; cin >> n >> k;
	int a = 15 * 60, b = 18 * 60, c = 21 * 60;
	int diff = 24 * 60 + k;
	vi ans;
	int from = n * 24 * 60, to = (n + 1) * 24 * 60 - 1;
	while (min(a, min(b, c)) <= to + diff) {
		if (from <= a && a <= to) ans.push_back(a);
		if (from <= b && b <= to) ans.push_back(b);
		if (from <= c && c <= to) ans.push_back(c);
		a += diff;
		b += diff;
		c += diff;
	}
	sort(all(ans));
	cout << ans.size() << "\n";
	for (int i : ans) cout << setw(2) << setfill('0') << (i / 60) % 24 << ":" << setw(2) << setfill('0') << (i % 60) << "\n";
}
