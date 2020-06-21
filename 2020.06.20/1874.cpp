#include <bits/stdc++.h>

using namespace std;

stack<int> s;

int main() {
	 cin.tie(0)->sync_with_stdio(0);
	 int n, next = 1; cin >> n;
	 string ans;

	 for (int i = 0; i < n; i++) {
	 	int a; cin >> a;
	 	if (s.empty() || s.top() < a) {
	 		if (next > a) {
	 			cout << "NO";
	 			return 0;
	 		}
	 		for (; next <= a; next++) {
	 			s.push(next);
	 			ans += "+\n";
	 		}
	 		s.pop();
	 		ans += "-\n";
	 	} else if (s.top() >= a) {
	 		while (1) {
	 			int out = s.top(); s.pop();
	 			ans += "-\n";
	 			if (out == a) break;
	 			if (out < a) {
	 				cout << "NO";
	 				return 0;
	 			}
	 		}
	 	}
	 }

	 cout << ans;
}