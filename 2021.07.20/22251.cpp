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

vector<vi> table = {
	   //0, 1, 2, 3, 4, 5, 6
		{1, 1, 1, 0, 1, 1, 1}, //0
		{0, 0, 1, 0, 0, 0, 1}, //1
		{1, 0, 1, 1, 1, 1, 0}, //2
		{1, 0, 1, 1, 0, 1, 1}, //3
		{0, 1, 1, 1, 0, 0, 1}, //4
		{1, 1, 0, 1, 0, 1, 1}, //5
		{1, 1, 0, 1, 1, 1, 1}, //6
		{1, 0, 1, 0, 0, 0, 1}, //7
		{1, 1, 1, 1, 1, 1, 1}, //8
		{1, 1, 1, 1, 0, 1, 1}, //9
};

string _fill(string a, int k) {
	while (a.size() < k) a.insert(a.begin(), '0');
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, p, x; cin >> n >> k >> p >> x;
	string origin = _fill(to_string(x), k);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		string s = _fill(to_string(i), k);
		int f = 1, cnt = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < 7; j++) if (table[s[i] - '0'][j] != table[origin[i] - '0'][j]) ++cnt;
		}
		if (f && cnt <= p && cnt) ++ans;
	}
	cout << ans;
}
