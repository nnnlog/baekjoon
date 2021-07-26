#include <bits/stdc++.h>

using namespace std;

string nxt(string s) {
	//reverse(s.begin(), s.end());
	int chk = 0;
	for (int i = (int)s.size() - 1; i >= 0; i--) {
		if (s[i] != 'z') {
			s[i]++;
			chk = 1;
			break;
		}
		s.pop_back();
	}
	if (!chk) {
		return "";
	}
	//reverse(s.begin(), s.end());
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int w, n, i = 0;
	cin >> w >> n;
	vector<pair<string, int>> vec(w);
	for (auto &[s, z] : vec) cin >> s, z = ++i;
	sort(vec.begin(), vec.end());
	//for (const auto &[a, b] : vec) cout << a << "\n";
	while (n--) {
		int a;
		string s;
		cin >> a >> s;
		auto one = lower_bound(vec.begin(), vec.end(), make_pair(s, 0));
		auto x = nxt(s);
		auto two = x.empty() ? vec.end() : lower_bound(vec.begin(), vec.end(), make_pair(x, 0));
		int cnt = two - one;
		//cout << nxt(s) << " " << one - vec.begin() << " " << two - vec.begin() << "\n";
		if (cnt < a || one == vec.end() || one->first.substr(0, s.size()) != s) cout << "-1\n";
		else cout << (one + a - 1)->second << "\n";
	}
}
