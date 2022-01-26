#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	stack<char> st;
	mpii mp = {
			{'*', 1},
			{'/', 1},
	};
	for (char c: s) {
		if ('A' <= c && c <= 'Z') cout << c;
		else {
			if (c == ')') {
				while (st.top() != '(') cout << st.top(), st.pop();
				st.pop();
			} else if (c == '(') st.push(c);
			else {
				while (!st.empty() && st.top() != '(' && mp[st.top()] >= mp[c]) cout << st.top(), st.pop();
				st.push(c);
			}
		}
	}
	while (!st.empty()) cout << st.top(), st.pop();
}
