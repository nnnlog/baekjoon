#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mp;
vector<string> car;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		mp[name] = i;
		car.push_back(name);
	}

	int ans = 0;
	vector<string> after;
	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		int cnt = 0;
		for (const string &prevCar : after)
			if (mp[prevCar] < mp[name])
				cnt++;

		after.push_back(name);

		ans += (cnt < mp[name]);
	}

	cout << ans;
}
