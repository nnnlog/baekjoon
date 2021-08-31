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
	deque<pii> deq;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++) {
			int a; cin >> a;
			deq.emplace_back(a, i);
		}
	while (deq.size() > 1) {
		int t = deq.front().first; deq.pop_front();
		while (--t) deq.push_back(deq.front()), deq.pop_front();
	}
	cout << deq.front().second << " " << deq.front().first;
}
