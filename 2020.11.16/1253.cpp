#include <bits/stdc++.h>

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

	int n; cin >> n;
	vl vec(n);

	for (auto &i : vec) cin >> i;

	sort(vec.begin(), vec.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			ll c = vec[i] - vec[j];
			auto it = lower_bound(vec.begin(), vec.end(), c);
			if (it < vec.end() && *it == c) {
				//cout << i << " " << j << "\n";
				if (vec.begin() + i == it || vec.begin() + j == it) {
					int f = 0;
					for (auto k = it + 1; k < vec.end() && k < it + 4; k++) {
						int ki = k - vec.begin();
						if (*k == c && ki != i && ki != j) {
							f = 1;
							break;
						}
					}

					if (!f) continue;
				}

				ans++;
				break;
			}
		}
	}

	cout << ans;
}
