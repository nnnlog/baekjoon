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


typedef pair<int, pair<int, int>> A;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, T; cin >> T >> n;
	priority_queue<A> pq;
	while (n--) {
		int a, b, c; cin >> a >> b >> c;
		pq.push({c, {-a, b}});
	}
	while (T-- && !pq.empty()) {
		auto top = pq.top(); pq.pop();
		int c = top.first, a = -top.second.first, b = top.second.second;
		--c, --b;
		if (b > 0) {
			pq.push({c, {-a, b}});
		}
		cout << a << "\n";
	}
}
