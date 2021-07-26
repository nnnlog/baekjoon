#include <bits/stdc++.h>

using namespace std;

void replace(string &str, char from, char to) {
	for (char &s : str) if (s == from) s = to;
}

void uppercase(string &str) {
	for (char &s : str) if ('a' <= s && s <= 'z') s -= 'a' - 'A';
}

void normalize_whitespace(string &str) {
	vector<string> split;
	string tmp;
	for (char a : str) {
		if (a == ' ') {
			split.push_back(tmp);
			tmp = "";
		} else tmp.push_back(a);
	}

	if (!tmp.empty()) split.push_back(tmp);

	str = "";
	for (auto s : split) if (s != "") str += s + " ";
}

string trim(string &str) {
	for (int i = 0; i < str.size();) {
		if (str[i] != ' ') break;
		str.erase(i, 1);
	}
	reverse(str.begin(), str.end());
	for (int i = 0; i < str.size();) {
		if (str[i] != ' ') break;
		str.erase(i, 1);
	}
	reverse(str.begin(), str.end());

	return str;
}

void normalize_whitespace_with_delta(string &str, char delt) {
	vector<string> split;
	string tmp;
	for (char a : str) {
		if (a == delt) {
			split.push_back(tmp);
			tmp = "";
		} else tmp.push_back(a);
	}

	if (!tmp.empty()) split.push_back(tmp);

	str = "";
	for (auto s : split) str += trim(s) + string(1, delt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	string tmp;
	getline(cin, tmp);

	for (int i = 1; i <= n; i++) {
		string a, b;
		getline(cin, a);
		getline(cin, b);

		trim(a);
		trim(b);

		uppercase(a);
		uppercase(b);

		normalize_whitespace(a);
		normalize_whitespace(b);

		for (auto p : vector<pair<char, char>>{
				{'{', '('},
				{'[', '('},
				{'}', ')'},
				{']', ')'},
				{',', ';'},
				{'|', '.'},
				{'|', ':'},
		}) {
			replace(a, p.first, p.second);
			replace(b, p.first, p.second);

			normalize_whitespace_with_delta(a, p.second);
			normalize_whitespace_with_delta(b, p.second);
		}

		//cout << a << "\n" << b << "\n";
		cout << "Data Set " << i << ": " << (a == b ? "" : "not ") << "equal\n\n";
	}
}