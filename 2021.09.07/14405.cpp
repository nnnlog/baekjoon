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

	string s; cin >> s;
	while (!s.empty()) {
		int f = 0;
		for (const auto &a : vector<string>{
			"pi", "ka", "chu"
		})
			if (s.find(a) == 0) {
				f = 1;
				s.erase(0, a.size());
				break;
			}
		if (!f) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
