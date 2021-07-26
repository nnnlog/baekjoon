#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll qu, n, id = 0; cin >> qu >> n;
	vector<stack<ll>> mod(n);
	stack<ll> q;
	for (ll i = 0; i < qu; i++) {
		ll a; cin >> a;
		if (a == 1) {
			ll b; cin >> b;
			q.push(b % n);
			mod[b % n].push(id++);
			//cout << "PUSH" << b % n << " " << id - 1 << "\n";
		} else if (a == 2) {
			if (!q.empty()) {
				int f = q.top(); q.pop();
				mod[f].pop();
				--id;
			}
		} else {
			if (!q.empty()) {
				ll ans = 1e9, f = 0;
				for (const auto &q : mod) {
					if (q.empty()) {
						f = 1;
						break;
					}
					ans = min(ans, q.top());
				}
				//cout << "D" << ans << " " << id << "\n";
				cout << (f ? -1 : id - ans) << "\n";
			} else cout << "-1\n";
		}
	}
}
