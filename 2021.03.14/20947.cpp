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

	int n;
	cin >> n;
	vector<vi> garo(n), sero(n), s_garo(n), s_sero(n);
	vector<vi> mp(n, vi(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c != '.') {
				if (c == 'X') mp[i][j] = 1, garo[i].push_back(j), sero[j].push_back(i);
				else mp[i][j] = 2, s_garo[i].push_back(j), s_sero[j].push_back(i);
			};
		}

	for (auto &v : garo) v.push_back(n), v.push_back(-1);
	for (auto &v : sero) v.push_back(n), v.push_back(-1);
	for (auto &v : s_garo) v.push_back(n + 1), v.push_back(-2);
	for (auto &v : s_sero) v.push_back(n + 1), v.push_back(-2);

	for (auto &v : garo) sort(all(v));
	for (auto &v : sero) sort(all(v));
	for (auto &v : s_garo) sort(all(v));
	for (auto &v : s_sero) sort(all(v));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!mp[i][j]) {

				if (*--lower_bound(all(garo[i]), j) < *--lower_bound(all(s_garo[i]), j)) {
					cout << ".";
					continue;
				}

				if (*upper_bound(all(garo[i]), j) > *upper_bound(all(s_garo[i]), j)) {
					cout << ".";
					continue;
				}

				if (*--lower_bound(all(sero[j]), i) < *--lower_bound(all(s_sero[j]), i)) {
					cout << ".";
					continue;
				}

				if (*upper_bound(all(sero[j]), i) > *upper_bound(all(s_sero[j]), i)) {
					cout << ".";
					continue;
				}

				cout << "B";
			} else if (mp[i][j] == 1) cout << "X";
			else cout << "O";
		}
		cout << "\n";
	}
}
