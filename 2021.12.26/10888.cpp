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

ll cnt = 0, edge = 0;

ll s(ll i) {
	return i * (i - 1) / 2;
}

vl dp(100001);

int UF[100001], UFC[100001];
int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	cnt -= s(UFC[a]) + s(UFC[b]);
	edge -= dp[UFC[a]] + dp[UFC[b]];
	UFC[b] += UFC[a], UFC[a] = 0;
	UF[a] = b;
	cnt += s(UFC[b]);
	edge += dp[UFC[b]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (ll i = 1; i < 1e5; i++) dp[i + 1] = dp[i] + i * (i + 1) / 2;

	int n; cin >> n;
	iota(UF, UF + n + 1, 0);
	fill(UFC, UFC + n + 1, 1);
	while (--n) {
		int i; cin >> i;
		merge(i, i + 1);
		cout << cnt << " " << edge << "\n";
	}
}
