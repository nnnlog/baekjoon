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

	int T; cin >> T;
	while (T--) {
		ll n, ans = 0; cin >> n;
		priority_queue<ll, vl, greater<>> pq;
		while (n--) {
			int a; cin >> a;
			pq.push(a);
		}
		while (pq.size() > 1) {
			ll a = pq.top();
			pq.pop();
			ll b = pq.top();
			pq.pop();
			pq.push(a + b);
			ans += a + b;
		}
		cout << ans << "\n";
	}
}
