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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, ans = 0; cin >> n;
	stack<int> s;
	while (n--) {
		int a; cin >> a;
		while (!s.empty() && s.top() <= a) s.pop();
		ans += s.size();
		s.push(a);
	}
	cout << ans;
}
