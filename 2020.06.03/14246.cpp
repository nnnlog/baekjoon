#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

vector<ull> l, sum;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;

	l.resize(n);
	sum.resize(n);
	for (int i = 0; i < n; i++) cin >> l[i];

	for (int i = 0; i < n; i++) {
		sum[i] = l[i] + sum[max(0, i - 1)];
	}

	ull k;
	cin >> k;

	ull ans = 0;
	for (int i = 0; i < n; i++) {
		auto q = upper_bound(sum.begin(), sum.end(), k + (i ? sum[i - 1] : 0));
		ans += sum.end() - q;
	}

	cout << ans;
}
