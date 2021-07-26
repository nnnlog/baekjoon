#include <bits/stdc++.h>

using namespace std;

struct A {
	int pos, diff, total;
};

vector<long long> mp(200001);
stack<A> process;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q, total = 0;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		mp[i] = a;
	}

	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) { //값 추가
			int a, b;
			cin >> a >> b;
			process.push({a, b, total});
		} else {
			int cnt;
			cin >> cnt;

			if (t == 2) cnt = n - cnt;
			total += cnt;
			total %= n;
		}
	}

	while (!process.empty()) {
		auto a = process.top();
		process.pop();

		int pos = a.total + a.pos;
		if (pos > n) {
			pos %= n;
		}
		mp[pos] += a.diff;
	}

	for (int i = 1; i <= n; i++) {
		if (total + i > n) cout << mp[(i + total) % n] << " ";
		else cout << mp[i + total] << " ";
	}
}
