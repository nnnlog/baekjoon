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

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string S, T;
		cin >> S >> T;
		pii a, b;
		for (const auto &c : S) if (c == '0') ++a.first; else if (c == '1') ++a.second;
		for (const auto &c : T) if (c == '0') ++b.first; else ++b.second;
		int q = S.size() - a.first - a.second;
		int ans = q;
		if (a.first + q < b.first) {
			cout << "Case " << i << ": -1\n";
			continue;
		}
		int ch_t = b.second - a.second;
		int ch_o = q - ch_t;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == '?') {
				if (!ch_o) S[j] = '1', --ch_t;
				else if (!ch_t) S[j] = '0', --ch_o;
				else if (T[j] == '1') S[j] = '1', --ch_t;
				else S[j] = '0', --ch_o;
			}
		}
		vi pos;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == '1' && T[j] == '0') pos.emplace_back(j);
		}
		//cout << S << " " << ans << "\n";
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == '0' && T[j] == '1') {
				if (!pos.empty()) S[j] = '1', S[pos.back()] = '0', pos.pop_back(), ++ans;
				else ++ans, S[j] = '1';
			}
		}

		cout << "Case " << i << ": " << ans << "\n";
	}
}
