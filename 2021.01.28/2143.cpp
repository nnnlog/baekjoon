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

	int t, n, m;
	cin >> t;

	mpii sum;
	cin >> n;
	vi A(n + 1);
	for (int i = 1; i <= n; i++) cin >> A[i], A[i] += A[i - 1];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			sum[A[j] - A[i - 1]]++;

	cin >> m;
	vi B(m + 1);
	for (int i = 1; i <= m; i++) cin >> B[i], B[i] += B[i - 1];

	ll ans = 0;
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j++) {
			int s = t - B[j] + B[i - 1];
			ans += sum[s];
		}

	cout << ans;
}
