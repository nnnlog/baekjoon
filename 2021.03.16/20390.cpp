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

typedef __int128 i128;

ostream &operator<<(ostream &dest, __int128 value) {
	ostream::sentry s(dest);
	if (s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while (tmp != 0);
		if (value < 0) {
			--d;
			*d = '-';
		}
		int len = end(buffer) - d;
		if (dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(ios_base::badbit);
		}
	}
	return dest;
}

i128 input(i128 &a) {
	ull t;
	cin >> t;
	return a = t;
}

int UF[10001];

int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}

int merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) return UF[a] = b, 1;
	return 0;
}

i128 n, a, b, c, d;
vector<i128> vec;

i128 dist(i128 i, i128 j) {
	if (i > j) swap(i, j);
	return ((vec[i - 1] * a + vec[j - 1] * b) % c) ^ d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input(n);
	input(a);
	input(b);
	input(c);
	input(d);

	vec.resize(n);
	for (auto &i : vec) input(i);

	priority_queue<pair<i128, i128>, vector<pair<i128, i128>>, greater<>> pq;
	vector<i128> key(n + 1, numeric_limits<i128>::max());
	vector<int> inMST(n + 1, 0);
	vector<int> par(n + 1, 0);

	pq.push(make_pair(0, 1));
	key[1] = 0;

	while (!pq.empty()) {
		i128 u = pq.top().second;
		pq.pop();

		inMST[u] = true;

		for (int v = 1; v <= n; v++) {
			i128 weight = dist(v, u);
			if (!inMST[v] && key[v] > weight && u != v) {
				key[v] = weight;
				par[v] = u;
				pq.push({key[v], v});
			}
		}
	}

	i128 ans = 0;
	for (int i = 2; i <= n; i++) ans += dist(i, par[i]);
	cout << ans;
}
