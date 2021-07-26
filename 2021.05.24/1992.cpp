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

int mp[65][65];

bool equal(pii A, pii B) {
	int ret = 0;
	for (int i = A.first; i <= B.first; i++)
		for (int j = A.second; j <= B.second; j++)
			ret |= mp[i][j] != mp[A.first][A.second];
	return !ret;
}

string solve(pii A, pii B) {
	if (A.first == B.first && A.second == B.second) return string(1, mp[A.first][A.second] + '0');
	if (equal(A, B)) return string(1, mp[A.first][A.second] + '0');
	int midX = (A.first + B.first) >> 1, midY = (A.second + B.second) >> 1;
	return "(" +
	       solve(A, {midX, midY})
	       + solve({A.first, midY + 1}, {midX, B.second})
	       + solve({midX + 1, A.second}, {B.first, midY})
	         + solve({midX + 1, midY + 1}, B)
	       + ")";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			mp[i][j] = c - '0';
		}
	cout << solve({1, 1}, {n, n});
}
