#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cin.ignore();
		set<string> vec;
		while (n--) {
			string str; getline(cin, str);
			vec.insert(str);
		}
		int f = 0;
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			auto ptr = next(it);
			if (ptr != vec.end() && ptr->find(*it) == 0) {
				f = 1;
				break;
			}
		}
		cout << (f ? "NO" : "YES") << "\n";
	}
}
