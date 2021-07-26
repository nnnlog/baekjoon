#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;


int diff(string a, string b) {
	int ret = 0;
	for (int i = 0; i < 4; i++) ret += (a[i] != b[i]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<string> vec(n);

		unordered_map<string, int> cnt;

		for (auto &i : vec) cin >> i, cnt[i]++;
		sort(all(vec));
		vec.erase(unique(all(vec)), vec.end());

		int ans = 1e9;
		for (int i = 0; i < vec.size(); i++) {
			if (cnt[vec[i]] >= 3) {
				ans = 0;
				break;
			}
			if (cnt[vec[i]] == 2) {
				for (int j = 0; j < vec.size(); j++) {
					if (j == i) continue;
					ans = min(ans, diff(vec[i], vec[j]) * 2);
				}
			}
			for (int j = 0; j < vec.size(); j++) {
				if (j == i) continue;
				for (int k = 0; k < vec.size(); k++) {
					if (k == i || k == j) continue;
					string a = vec[i], b = vec[j], c = vec[k];
					ans = min(ans, diff(a, b) + diff(b, c) + diff(a, c));
				}
			}
		}

		cout << ans << "\n";
	}
}
