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

vector<char> ans;
int sum, tmp, flag, n;
void solve(int k) {
	if (k > n) {
		if (tmp) sum += (flag ? -1 : 1) * tmp;
		if (!sum) {
			for (int i = 0; i < ans.size(); i++) {
				cout << i + 1 << ans[i];
			}
			cout << ans.size() + 1 << "\n";
		}
		return;
	}

	int t = tmp, o = flag, os = sum;
	tmp *= 10;
	tmp += k;
	ans.push_back(' ');
	solve(k + 1);
	ans.pop_back();
	tmp /= 10;
	tmp = t;
	flag = o;
	sum = os;

	sum += (flag ? -1 : 1) * tmp;
	ans.push_back('+');
	tmp = k;
	flag = 0;
	solve(k + 1);
	ans.pop_back();
	tmp = t;
	flag = o;
	sum = os;

	sum += (flag ? -1 : 1) * tmp;
	ans.push_back('-');
	tmp = k;
	flag = 1;
	solve(k + 1);
	ans.pop_back();
	tmp = t;
	flag = o;
	sum = os;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		sum = 0;
		tmp = 1;

		cin >> n;
		solve(2);
		cout << "\n";
	}
}
