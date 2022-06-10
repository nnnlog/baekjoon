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

struct MyFile {
	string owner;
	unordered_map<string, int> *group;
	int owner_perm, group_perm, other_perm;
};

bool has_permission(char op, int i) {
	if (op == 'R') return i & (1 << 2);
	if (op == 'W') return i & (1 << 1);
	if (op == 'X') return i & (1 << 0);
	abort();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unordered_map<string, unordered_map<string, int>> users_in_group;
	unordered_map<string, MyFile> file_info;
	int u, f;
	cin >> u >> f >> ws;
	while (u--) {
		string s;
		getline(cin, s);

		if (s.find(' ') != string::npos) {
			stringstream ss(s);
			string name;
			ss >> name >> ws;

			string g;
			while (getline(ss, g, ',')) users_in_group[g][name] = 1;

			users_in_group[name][name] = 1;
		} else users_in_group[s][s] = 1;
	}

	while (f--) {
		string name, perm, owner, group;
		cin >> name >> perm >> owner >> group;

		file_info[name] = {
				owner,
				&users_in_group[group],
				perm[0] - '0',
				perm[1] - '0',
				perm[2] - '0',
		};
	}

	int q;
	cin >> q;
	while (q--) {
		string user, filename;
		char op;
		cin >> user >> filename >> op;

		auto &file = file_info[filename];
		if (file.owner == user) cout << has_permission(op, file.owner_perm);
		else if (file.group->count(user)) cout << has_permission(op, file.group_perm);
		else cout << has_permission(op, file.other_perm);
		cout << "\n";
	}
}
