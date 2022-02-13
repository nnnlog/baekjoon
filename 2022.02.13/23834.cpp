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

	int n, m; cin >> n >> m;

    vi A(n + 1), B(n + 1);
    for (int &i : A | views::drop(1)) cin >> i;
    for (int &i : B | views::drop(1)) cin >> i;

    vl sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + A[i];

    deque<int> deq;
    deq.push_back(0);

    vl dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int f = deq.front();
        dp[i] = dp[f] + sum[i - 1] - sum[f] - A[i];

        if (i - f >= m) deq.pop_front();
        while (!deq.empty() && dp[i] >= dp[deq.back()] + sum[i] - sum[deq.back()]) deq.pop_back();
        deq.push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i + m <= n) ans = max(ans, dp[i] + sum[i + m] - sum[i] + B[i + m]);
        else ans = max(ans, dp[i] + sum[n] - sum[i]);
    }

    cout << ans;
}
