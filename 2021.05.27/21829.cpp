#include "secret.h"
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

int n;
int dp[1001][1001];

void init(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1;
	for (int i = mid - 1; i >= l; i--) dp[i][mid] = Secret(dp[i][i], dp[i + 1][mid]);
	for (int i = mid + 2; i <= r; i++) dp[mid + 1][i] = Secret(dp[mid + 1][i - 1], dp[i][i]);
	init(l, mid);
	init(mid + 1, r);
}

void Init(int N, int A[]) {
	memset(dp, -1, sizeof(dp));
	n = N;
	for (int i = 0; i < N; i++) dp[i][i] = A[i];
	init(0, N - 1);
}

int Query(int L, int R) {
	if (dp[L][R] != -1) return dp[L][R];
	for (int i = L; i < R; i++) if (dp[L][i] != -1 && dp[i + 1][R] != -1) return Secret(dp[L][i], dp[i + 1][R]);
	assert(0);
}
