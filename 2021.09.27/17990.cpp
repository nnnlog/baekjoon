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

vi UF, sum;
int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) sum[a] += sum[b], UF[b] = a;
}

int up(int n) {
	return n % 10 ? n + 10 - (n % 10) : n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	UF.resize(n), sum.resize(n);
	iota(all(UF), 0);
	vi vec(n);
	for (int &i : vec) cin >> i;
	ll ans = 0, cnt = 0;
	stack<int> qry;
	while (n--) {
		int a; cin >> a;
		qry.push(--a);
	}
	ll rounded = 0;
	while (!qry.empty()) {
		auto k = qry.top(); qry.pop();
		++cnt;
		sum[k] = vec[k];
		rounded += up(vec[k]);
		vec[k] = -1;

		for (int i = k + 1; i < vec.size() && vec[i] == -1 && find(k) != find(i); i++) {
			--cnt;
			rounded -= up(sum[find(k)]);
			rounded -= up(sum[find(i)]);
			merge(k, i);
			rounded += up(sum[find(k)]);
		}
		for (int i = k - 1; i >= 0 && vec[i] == -1 && find(k) != find(i); i--) {
			--cnt;
			rounded -= up(sum[find(k)]);
			rounded -= up(sum[find(i)]);
			merge(k, i);
			rounded += up(sum[find(k)]);
		}

		ans = max(ans, rounded * cnt);
	}
	cout << ans;
}
