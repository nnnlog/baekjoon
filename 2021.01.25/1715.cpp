#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, sum = 0; cin >> n;
	priority_queue<int, vi, greater<>> pq;
	while (n--) {
		int a; cin >> a;
		pq.push(a);
	}
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		a += pq.top(); pq.pop();
		sum += a;
		pq.push(a);
	}
	cout << sum;
}
