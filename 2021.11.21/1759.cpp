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

vector<char> vec;
string ans;
int l, a, b;

void solve(int k) {
	if (a + b == l) {
		if (a < 1 || b < 2) return;
		cout << ans << "\n";
		return;
	}
	if (k >= vec.size()) return;

	int c = vec[k] == 'a' || vec[k] == 'e' || vec[k] == 'i' || vec[k] == 'o' || vec[k] == 'u';
	if (c) a++;
	else b++;
	ans.push_back(vec[k]);

	solve(k + 1);

	if (c) a--;
	else b--;
	ans.pop_back();

	solve(k + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int c; cin >> l >> c;
	vec.resize(c);
	for (auto &i : vec) cin >> i;
	sort(all(vec));
	solve(0);
}
