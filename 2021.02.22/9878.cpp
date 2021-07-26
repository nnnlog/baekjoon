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
	priority_queue<ld, vld, greater<>> T, D;
	while (n--) {
		char c; ld a;
		cin >> c >> a;
		if (c == 'T') T.push(a);
		else D.push(a);
	}
	ld curr_speed = 1, pos = 0, ans = 0;
	while (!T.empty() || !D.empty()) {
		if (T.empty()) {
			auto d = D.top(); D.pop();
			ans += (d - pos) * curr_speed;
			pos = d;
		} else if (D.empty()) {
			auto t = T.top(); T.pop();
			pos += (t - ans) * (1 / curr_speed);
			ans = t;
		} else {
			auto d = D.top();
			auto t = T.top();
			if (ans + (d - pos) * curr_speed <= t) {
				ans += (d - pos) * curr_speed;
				pos = d;
				D.pop();
			} else {
				pos += (t - ans) * (1 / curr_speed);
				ans = t;
				T.pop();
			}
		}
		++curr_speed;
	}

	ans += (1000 - pos) * curr_speed;
	cout << (ll)round(ans);
}
