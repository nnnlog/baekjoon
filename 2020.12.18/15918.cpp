#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

vi vis, ans;
ll cnt = 0;
int n, x, y;

void dfs() {
	int pos = 0;
	for (int i = 1; i <= 2 * n; i++)
		if (!ans[i]) {
			pos = i;
			break;
		}

	//for (const auto &i : ans) cout << i << " ";
	//cout << "\n";
	if (!pos) {
		cnt++;
		return;
	}

	for (int k = 1; k <= n; k++) {
		if (!vis[k]) {
			if (pos + k + 1 > 2 * n) break;
			if (ans[pos + k + 1]) continue;

			vis[k] = 1;
			ans[pos] = k;
			ans[pos + k + 1] = k;

			dfs();

			ans[pos] = 0;
			ans[pos + k + 1] = 0;
			vis[k] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> x >> y;
	vis.resize(n + 1);
	ans.resize(n * 2 + 1);

	vis[y - x - 1] = 1;
	ans[x] = y - x - 1;
	ans[y] = y - x - 1;

	dfs();
	cout << cnt;
}
