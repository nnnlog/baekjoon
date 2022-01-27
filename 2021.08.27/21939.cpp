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

	set<pii> S;
	int n;
	cin >> n;
	while (n--) {
		int p, l;
		cin >> p >> l;
		S.emplace(l, p);
	}
	map<int, int> remove;
	int m;
	cin >> m;
	while (m--) {
		string s;
		cin >> s;
		if (s == "add") {
			int p, l;
			cin >> p >> l;
			S.emplace(l, p);
		}
		if (s == "recommend") {
			int p;
			cin >> p;
			if (p == 1) {
				while (remove[S.rbegin()->second]) --remove[S.rbegin()->second], S.erase(--S.end());
				cout << S.rbegin()->second << "\n";
			} else {
				while (remove[S.begin()->second]) --remove[S.begin()->second], S.erase(S.begin());
				cout << S.begin()->second << "\n";
			}
		}
		if (s == "solved") {
			int p;
			cin >> p;
			remove[p]++;
		}
	}
}
