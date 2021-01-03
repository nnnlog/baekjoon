#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int vis[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, open = 0, ans = 0; cin >> n;
	n <<= 1;
	while (n--) {
		int a; cin >> a;
		if (!vis[a]) ++open;
		else if (vis[a] == 1) --open;
		++vis[a];

		ans = max(ans, open);
	}
	cout << ans;
}
