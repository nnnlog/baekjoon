#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int ans, n;
void dfs(string a) {
	if (a.size() == n) {
		int c = 0;
		for (const auto &b : a) c += b - '0';
		ans += c % 3 == 0;
	} else {
		vector<char> vec = {'0', '1', '2'};
		for (auto &c : vec) {
			if (a.empty() && c == '0') continue;
			a.push_back(c);
			dfs(a);
			a.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	dfs("");
	cout << ans;
}
