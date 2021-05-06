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

	int n; cin >> n;
	string ans(n, 0);
	vi vec(n), idx(n + 1, -1);
	for (int i = 0; i < n; i++) cin >> vec[i], idx[vec[i]] = i;
	ans[vec.front()] = 'a';
	for (int i = 1; i < n; i++) {
		char a = ans[vec[i - 1]];
		if (idx[vec[i - 1] + 1] < idx[vec[i] + 1]) ans[vec[i]] = a;
		else ans[vec[i]] = a + 1;
	}
	//cout << ans << "\n";
	sort(all(ans));
	ans.erase(unique(all(ans)), ans.end());
	cout << ans.size();
}
