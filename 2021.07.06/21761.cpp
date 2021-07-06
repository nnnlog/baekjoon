#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, k;
	cin >> n >> k;
	vector<ll> values('E');
	cin >> values['A'] >> values['B'] >> values['C'] >> values['D'];
	vector<vector<ll>> vec('E');
	while (n--) {
		char c;
		cin >> c;
		int a;
		cin >> a;
		vec[c].push_back(a);
	}
	for (auto &v : vec) sort(v.begin(), v.end());
	vector<pair<char, ll>> ans;
	while (k--) {
		vector<pair<pll, char>> srt;
		for (char i = 'A'; i <= 'D'; i++) if (!vec[i].empty()) srt.emplace_back(pll(vec[i].back(), values[i]), i);
		sort(srt.begin(), srt.end(), [](auto a, auto b) {
			return __int128(b.first.second) * a.first.first > __int128(a.first.second) * b.first.first;
		});
		char selc = srt.front().second;
		ans.emplace_back(selc, vec[selc].back());
		values[selc] += vec[selc].back();
		vec[selc].pop_back();
	}
	for (const auto &[c, a] : ans) cout << c << " " << a << "\n";
}
