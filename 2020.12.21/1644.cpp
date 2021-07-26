#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

vi vis(4000001);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vi prime;

	int n; cin >> n;
	int k = n;
	for (int i = 2; i <= k; i++) {
		if (!vis[i]) prime.push_back(i);
		for (int j = i; j <= k; j += i) vis[j] = 1;
	}

	/*int chk = n == 1;
	for (int i = 2; i < n; i++)
		if (n % i == 0) chk = 1;
	if (!chk) prime.push_back(n);*/
	if (!prime.size()) {
		cout << "0";
		return 0;
	}

	int l = 0, r = 1, sum = prime[0], ans = 0;
	for (; l < prime.size(); ) {
		if (n == sum) ans++;
		if (n <= sum) {
			sum -= prime[l++];
		} else {
			if (r < prime.size()) sum += prime[r++];
			else break;
		}
	}

	cout << ans;
}
