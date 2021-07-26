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

unordered_map<ll, ll> cnt;
vl vec;
ll ans = 0;
ll n, s;

void init(int i, ll sum) {
	cnt[sum += vec[i]]++;
	if (sum == s) ans++;
	for (int j = i + 1; j < n / 2; j++) init(j, sum);
}
void solve(int i, ll sum) {
	sum += vec[i];
	if (cnt.count(s - sum)) ans += cnt[s - sum];
	if (sum == s) ans++;
	for (int j = i + 1; j < n; j++) solve(j, sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> s;
	vec.resize(n);
	for (auto &i : vec) cin >> i;

	for (int i = 0; i < n / 2; i++) init(i, 0);
	for (int i = n / 2; i < n; i++) solve(i, 0);

	cout << ans;
}
