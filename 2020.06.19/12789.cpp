#include <bits/stdc++.h>

using namespace std;

queue<int> main_line;
stack<int> waiting;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		main_line.push(a);
	}

	int expected = 1;
	while (1) {
		if (!waiting.empty()) {
			int a = waiting.top();
			if (a == expected) {
				expected++;
				waiting.pop();
				continue;
			}
		}
		if (!main_line.empty()) {
			int a = main_line.front();
			main_line.pop();

			if (a == expected) {
				expected++;
			}else{
				waiting.push(a);
			}
		} else {
			if (waiting.empty()) {
				cout << "Nice";
				return 0;
			}
			if (waiting.top() == expected) {
				waiting.pop();
				expected++;
			}else{
				cout << "Sad";
				return 0;
			}
		}
	}
}
