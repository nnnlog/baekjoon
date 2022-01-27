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

	int n, q;
	cin >> n >> q;
	vi par(n + 1), cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> par[i];
		cnt[par[i]]++;
	}
	cout << n << " " << q << "\n";
	int m;
	cin >> m;
	q -= m;
	while (m--) {
		int a;
		cin >> a;
		cout << "2 " << a << "\n";
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++) if (!cnt[i]) Q.push(i);
	while (!Q.empty()) {
		auto top = Q.front();
		Q.pop();
		q--;
		cout << "1 " << top << " " << par[top] << "\n";
		if (!--cnt[par[top]]) Q.push(par[top]);
	}
	int root = max_element(all(cnt)) - cnt.begin();
	while (q-- > 0) cout << "1 " << root << " " << root << "\n";
}
