#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a; getline(cin, a);
	long long cnt = 0, ans = 0;
	for (int i = 0; i < a.size(); i++) {
		char c = a[i];
		if (c == '(' && a[i + 1] == ')') {
			ans += cnt;
			i++;
		} else if (c == '(') cnt++;
		else ++ans && cnt--;
	}
	
	cout << ans;
}