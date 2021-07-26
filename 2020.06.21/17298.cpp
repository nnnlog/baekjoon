#include <bits/stdc++.h>
using namespace std;

stack<int> s, ans;
vector<int> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	
	for (int i = n - 1; i >= 0; i--) {
		if (s.empty()) {
			ans.push(-1);
		}else{
			while (!s.empty() && s.top() <= v[i]) s.pop();
			ans.push(s.empty() ? -1 : s.top());
		}
		s.push(v[i]);
	}
	
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
}