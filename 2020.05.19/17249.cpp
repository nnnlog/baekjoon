#include <bits/stdc++.h>

using namespace std;

string str;

int solve(int start, int end) {
	int pos = str.find('@', start), cnt = 0;
	while (pos != string::npos && pos < end) {
		cnt++;
		pos = str.find('@', pos + 1);
	}
	return cnt;
}

int main() {
	cin >> str;

	cout << solve(0, str.find('(')) << " ";
	cout << solve(str.find(')'), str.size());
}
