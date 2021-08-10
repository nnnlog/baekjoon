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

struct FileStat {
	string parent;
	string name;
	bool is_directory = false;
	map<string, FileStat *> files;
	map<string, FileStat *> dirs;

	int cnt = 0;
	map<string, bool> kind;
};

// mv src/* target && rm -r src 라고 생각하고 구현
void move(FileStat *src, FileStat *target) {
	assert(src->is_directory && target->is_directory);
	for (auto [name, stat] : src->files) target->files[name] = stat, stat->parent = target->name;
	for (auto [name, stat] : src->dirs) {
		if (target->dirs.count(name)) move(stat, target->dirs[name]);
		else target->dirs[name] = stat, stat->parent = target->name;
	}
}

void init(FileStat *current) {
	current->cnt = current->files.size();
	for (auto [name, _] : current->files) current->kind[name] = true;

	for (auto [_, stat] : current->dirs) {
		init(stat);

		current->cnt += stat->cnt;
		for (auto [name, _] : stat->kind) current->kind[name] = true;
	}
}

FileStat root{.name = "main", .is_directory = true};

map<string, vector<FileStat*>> info;
void insert(FileStat *current) {
	assert(current->is_directory);
	for (auto &stat : info[current->name]) {
		if (stat->is_directory) insert(current->dirs[stat->name] = stat);
		else current->files[stat->name] = stat;
	}
}

vector<string> split_slash(string &str) {
	vector<string> ret;
	string tmp;
	for (char c : str) {
		if (c == '/') ret.push_back(tmp), tmp.clear();
		else tmp.push_back(c);
	}
	ret.emplace_back(tmp);
	return ret;
}

FileStat *get_directory(string path, bool get_parent = false) {
	FileStat *ret = &root;
	auto it = split_slash(path);
	for (int i = 1; i < int(it.size()) - int(get_parent); i++) {
		//assert(ret->dirs.count(it[i]));
		ret = ret->dirs[it[i]];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<FileStat> ptr(n + m);
	for (int i = 0; i < n + m; i++) {
		FileStat *stat = &ptr[i];
		cin >> stat->parent >> stat->name >> stat->is_directory;
		info[stat->parent].emplace_back(stat);
	}
	insert(&root);
/*
	int k;
	cin >> k;
	while (k--) {
		string src, target;
		cin >> src >> target;
		auto stat = get_directory(src);
		get_directory(src, true)->dirs.erase(stat->name);
		move(stat, get_directory(target));
	}
*/
	init(&root);
	int q;
	cin >> q;
	while (q--) {
		string path;
		cin >> path;
		//assert(path.back() != '/');
		auto stat = get_directory(path);
		cout << stat->kind.size() << " " << stat->cnt << "\n";
	}
}
