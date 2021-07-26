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

	int n, t;
	cin >> n >> t;
	queue<int> q;
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		q.push(a);
	}
	queue<pair<int, pii>> deq;
	while (t--) {
		int a, f = 0;
		string s;
		cin >> a >> s;
		if (s[0] != 'n') {
			cin >> f;
		}
		deq.push({s[0], {a, f}});
	}
	set<int> pub;
	vector<pii> acq(n + 1);
	while (!q.empty()) {
		int turn = q.front();
		q.pop();
		int ans;
		if (!acq[turn].first) {
			auto gt = deq.front();
			deq.pop();
			ans = gt.second.first;
			if (gt.first == 'r') {
				pub.erase(gt.second.second);
			} else if (gt.first == 'a') acq[turn] = {ans, gt.second.second};
		}
		if (acq[turn].first) {
			cout << acq[turn].first << "\n";
			if (pub.find(acq[turn].second) == pub.end()) {
				pub.insert(acq[turn].second);
				acq[turn] = {0, 0};
			}
		} else cout << ans << "\n";
	}
}
