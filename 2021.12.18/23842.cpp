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

vi vec = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6};

int conv(int a) {
	return vec[a / 10] + vec[a % 10];
}

string str(int a) {
	string ret = a < 10 ? "0" : "";
	return ret + to_string(a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<string> ans(51, "impossible");
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (i + j > 99) continue;
			ans[conv(i) + conv(j) + conv(i + j) + 4] = str(i) + "+" + str(j) + "=" + str(i + j);
		}
	}

	int n; cin >> n;
	cout << ans[n];
}
