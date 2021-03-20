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

	int S; cin >> S;
	queue<tuple<int, int, int>> q;
	vector<vi> vis(5001, vi(5001));
	vis[1][0] = 1;
	q.push({1, 0, 0});
	while (!q.empty()) {
		auto f = q.front(); q.pop();
		if (get<0>(f) == S) {
			cout << get<2>(f);
			return 0;
		}
		auto push = [&](int nxt, int clip) {

			if (nxt < 0 || nxt > 5000) return;
			if (clip < 0 || clip > 5000) return;
			if (!nxt || !clip) return;
			if (vis[nxt][clip]) return;
			vis[nxt][clip] = 1;
			q.push({nxt, clip, get<2>(f) + 1});
		};
		if (get<1>(f)) push(get<0>(f) + get<1>(f), get<1>(f));
		push(get<0>(f) - 1, get<1>(f));
		push(get<0>(f), get<0>(f));
	}
}
