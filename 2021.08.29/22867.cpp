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

void erase(string &a) {
	while (a.find(':') != string::npos) a.erase(a.find(':'), 1);
	while (a.find('.') != string::npos) a.erase(a.find('.'), 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vpii vec;
	while (n--) {
		string a, b; cin >> a >> b;
		erase(a), erase(b);
		vec.emplace_back(atoi(a.c_str()), 1);
		vec.emplace_back(atoi(b.c_str()), -1);
	}
	sort(all(vec));
	int ans = 0, cnt = 0;
	for (const auto &[a, b] : vec) cnt += b, ans = max(ans, cnt);
	cout << ans;
}
