#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b;
	int _case = 1;
	do {
		getline(cin, a);
		getline(cin, b);

		if (a == "END" && b == "END") return 0;

		vector<int> l('z' + 1);
		for (const char &c : a) l[c]++;
		for (const char &c : b) l[c]--;

		bool flag = false;
		for (int i = 'a'; i <= 'z'; i++) if (l[i]) {
			flag = true;
			break;
		}

		cout << "Case " << _case++ << ": " << (flag ? "different" : "same") << "\n";
	} while (1);
}