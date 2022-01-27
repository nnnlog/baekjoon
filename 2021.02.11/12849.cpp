#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

vi graph[9] = {
		{},
		{2, 3}, //1
		{1, 3, 4}, //2
		{1, 2, 4, 5}, //3
		{2, 3, 5, 6}, //4
		{3, 4, 6, 8}, //5
		{4, 5, 7}, //6
		{6, 8}, //7
		{5, 7}, //8
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int d;
	cin >> d;
	vi ans(9);
	ans[1] = 1;
	while (d--) {
		vi nxt(9);
		for (int i = 1; i <= 8; i++)
			for (const auto &v : graph[i])
				nxt[v] += ans[i], nxt[v] %= 1000000007;
		ans = nxt;
	}
	cout << ans[1];
}
