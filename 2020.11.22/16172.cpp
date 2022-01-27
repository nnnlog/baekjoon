#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string tmp, s;
	getline(cin, tmp);
	for (const auto &c : tmp) {
		if ('0' <= c && c <= '9') continue;
		s.push_back(c);
	}


	string t;
	cin.ignore();
	getline(cin, t);

	cout << (s.find(t) != string::npos);
}
