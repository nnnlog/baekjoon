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
		int n; cin >> n;
		vi vec(n + 1);
		int go = 1;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (a == go) go++;
			else q.push(a);
			while (!q.empty() && q.front() == go) q.pop(), go++;
		}
		cout << (q.empty() ? "TAK" : "NIE") << "\n";
	}
}
