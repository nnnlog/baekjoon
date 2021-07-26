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

	int n, c;
	cin >> n >> c;
	vector<vi> vec(n + 1);
	vi cardIdx(c + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int a;
			cin >> a;
			vec[i].push_back(a);
			cardIdx[a] = i;
		}
	}
	vector<vpii> card(c + 1);
	cin.ignore();
	for (int i = 1; i <= c; i++) {
		string str;
		getline(cin, str);
		int ok = -1;
		for (char &j : str) {
			if (j == ',') {
				ok = -1;
				continue;
			}
			if (ok == -1) {
				ok = j == 'A';
			}
			if ('a' <= j && j <= 'z') {
				card[i].push_back({ok, j});
			}
			if ('0' <= j && j <= '9') {
				card[i].push_back({ok, j - '0'});
			}
		}
	}
	vi perm(c);
	iota(all(perm), 1);
	map<string, int> ans;
	do {
		vi expect(n + 1);
		string str;
		for (const auto &i : perm) {
			int owner = cardIdx[i];
			if (i != vec[owner][expect[owner]]) {
				goto no;
			}
			++expect[owner];
			for (const auto &[a, b] : card[i]) {
				if (a) str.push_back(b);
				else {
					if (str.size() <= b) {
						str = "ERROR";
						goto bye;
					}
					str.erase(b, 1);
				}
			}
		}
		bye:;
		if (str.empty()) str = "EMPTY";
		ans[str] = 1;
		no:;
	} while (next_permutation(all(perm)));
	for (auto [a, b] : ans) cout << a << "\n";
}
