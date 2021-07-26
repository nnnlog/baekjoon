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

ll ccw(pii x, pii y, pii z) {
	ll a = x.first, b = x.second;
	ll c = y.first, d = y.second;
	ll e = z.first, f = z.second;
	return a * d + c * f + e * b - b * c - d * e - f * a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vpii vec(n);
	for (auto &[a, b] : vec) cin >> a >> b;
	sort(all(vec));
	//pii ptr = vec.front();
	sort(vec.begin() + 1, vec.end(), [&](pii a, pii b) {
		ll c = ccw(vec[0], a, b);
		if (c < 0) return false;
		else if (c > 0) return true;
		else if (abs(a.first - vec[0].first) + abs(a.second - vec[0].second) < abs(b.first - vec[0].first) + abs(b.second - vec[0].second)) return true;
		else return false;
	});
	stack<pii> S;
	for (auto x : vec) {
		while (S.size() >= 2) {
			pii a = S.top(); S.pop();
			pii b = S.top();
			if (ccw(b, a, x) > 0) {
				S.push(a);
				break;
			}
		}
		S.push(x);
	}
	cout << S.size();
}
