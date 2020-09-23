#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	
	set<int> ham, human;
	
	int n, k; cin >> n >> k;
	cin.ignore();
	string ln; getline(cin, ln);
	int pos = 0;
	for (const auto &c : ln) {
		if (c == 'H') ham.insert(++pos);
		else human.insert(++pos);
	}
	ham.insert(1000000);
	
	int ans = 0;
	for (const auto &p : human) {
		auto it = ham.lower_bound(p - k);
		if (*it == 1000000) continue;
		if (*it <= p + k) {
			ans++;
			ham.erase(it);
		}
	}
	
	cout << ans;
}
