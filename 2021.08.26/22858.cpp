#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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

int SP[52][1'000'001];

int get(int a, ll k) {
	for (int i = 51; i >= 0; --i)
		if (k & (1LL << i)) a = SP[i][a];
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, k;
	cin >> n >> k;
	vi S(n + 1), D(n + 1);
	for (int &i : S | drop(1)) cin >> i;
	for (int &i : D | drop(1)) cin >> i;
	for (int i = 1; i <= n; i++) SP[0][i] = D[i];
	for (int i = 1; i <= 51; i++)
		for (int j = 1; j <= n; j++)
			SP[i][j] = SP[i - 1][SP[i - 1][j]];
	vi ans(n + 1);
	for (int i = 1; i <= n; i++) ans[get(i, k)] = S[i];
	for (int i : ans | drop(1)) cout << i << " ";
}
