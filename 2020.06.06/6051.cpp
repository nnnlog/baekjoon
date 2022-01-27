#include <bits/stdc++.h>

using namespace std;

stack<int> record[80001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char a;
		cin >> a;
		if (a == 'a') {
			int b; cin >> b;
			record[i] = record[i - 1];
			record[i].push(b);

			cout << b << "\n";
		} else if (a == 's') {
			record[i] = record[i - 1];
			if (!record[i].empty()) record[i].pop();
			cout << (record[i].empty() ? -1 : record[i].top()) << "\n";
		} else { //t
			int b; cin >> b;
			record[i] = record[b - 1];
			cout << (record[i].empty() ? -1 : record[i].top()) << "\n";
		}
	}

	/*for (int i = 1; i <= n; i++) {
		while (!record[i].empty()) {
			cout << record[i].top() << " ";
			record[i].pop();
		}
		cout << "\n";
	}*/
}
