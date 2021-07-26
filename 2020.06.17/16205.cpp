#include <bits/stdc++.h>

using namespace std;

vector<string> arr(4);
vector<string> split;

int main() {
	int n;
	string a, tmp;
	cin >> n >> a;

	arr[n] = a;
	switch (n) {
		case 1:
			for (char t : a) {
				if ('A' <= t && t <= 'Z') {
					split.push_back(tmp);
					tmp = string(1, t + ('a' - 'A'));
				} else tmp.push_back(t);
			}
			if (!tmp.empty()) split.push_back(tmp);
			break;
		case 2:
			for (char t : a) {
				if (t == '_') {
					split.push_back(tmp);
					tmp = "";
				} else tmp.push_back(t);
			}
			if (!tmp.empty()) split.push_back(tmp);
			break;
		case 3:
			tmp.push_back(a[0] + ('a' - 'A'));
			a.erase(0, 1);
			for (char t : a) {
				if ('A' <= t && t <= 'Z') {
					split.push_back(tmp);
					tmp = string(1, t + ('a' - 'A'));
				} else tmp.push_back(t);
			}
			if (!tmp.empty()) split.push_back(tmp);
			break;
	}

	for (int i = 1; i <= 3; i++) {
		if (arr[i] == "") {
			int first = 1;
			switch (i) {
				case 1:
					for (auto s : split) {
						if (!first) s[0] = s[0] - ('a' - 'A');
						else first = 0;
						arr[i].append(s);
					}
					break;
				case 2:
					for (auto s : split) {
						arr[i].append(s);
						arr[i] += "_";
					}
					arr[i].pop_back();
					break;
				case 3:
					for (auto s : split) {
						s[0] = s[0] - ('a' - 'A');
						arr[i].append(s);
					}
					break;
			}
		}
		cout << arr[i] << "\n";
	}
}