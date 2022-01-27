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

	int n;
	cin >> n;
	set<string> root;
	map<string, int> in;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		in[s] = 0;
		root.insert(s);
	}

	int m;
	cin >> m;
	map<string, vector<string>> par;
	while (m--) {
		string u, v;
		cin >> u >> v;
		in[v]++;
		par[u].emplace_back(v);
		root.erase(u);
	}

	queue<string> q;
	map<string, set<string>> child;
	for (const auto &[name, cnt] : in) {
		if (!cnt) q.push(name);
		child[name] = {};
	}

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		for (const auto &p : par[front]) {
			if (!--in[p]) {
				q.push(p);
			}
			child[p].insert(front);
			for (const auto &s : child[front]) child[p].erase(s);
		}
	}

	cout << root.size() << "\n";
	for (const auto &i : root) cout << i << " ";
	cout << "\n";

	for (const auto &[name, s] : child) {
		cout << name << " " << s.size() << " ";
		for (const auto &i : s) cout << i << " ";
		cout << "\n";
	}
}
