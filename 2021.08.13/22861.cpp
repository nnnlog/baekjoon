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
	FileStat *parent = nullptr;
	string name;
	int is_directory = false;

	map<string, FileStat *> files;
	map<string, FileStat *> dirs;

	int cnt = 0;
	map<string, bool> kind;
};

// mv src/* target && rm -r src 라고 생각하고 구현
void move(FileStat *src, FileStat *target) {
	for (auto &[name, stat] : src->files) target->files[name] = stat, stat->parent = target;
	for (auto &[name, stat] : src->dirs) {
		if (target->dirs.count(name)) move(stat, target->dirs[name]);
		else target->dirs[name] = stat, stat->parent = target;
	}
}

void init(FileStat *current) {
	current->cnt = current->files.size();
	for (auto &[name, _] : current->files) current->kind[name] = true;

	for (auto &[_, stat] : current->dirs) {
		init(stat);

		current->cnt += stat->cnt;
		for (auto &[name, _] : stat->kind) current->kind[name] = true;
	}
}

FileStat root{.name = "main", .is_directory = true};
map<string, vector<FileStat *>> info;

vector<FileStat> ptr(50001);
int nxt = 0;

FileStat *get() {
	assert(nxt < 50000);
	return &ptr[nxt++];
}

void insert(FileStat *parent) {
	for (auto &child : info[parent->name]) {
		child->parent = parent;
		if (child->is_directory) insert(parent->dirs[child->name] = child);
		else parent->files[child->name] = child;
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

FileStat *get_directory(string path, int create = 0) {
	FileStat *ret = &root;
	auto it = split_slash(path);
	for (int i = 1; i < it.size(); i++) {
		//assert(ret->dirs.count(it[i]) || a);
		if (!ret->dirs.count(it[i])) {
			//if (!create) assert(0);
			auto tmp = get();
			tmp->parent = ret;
			tmp->name = it[i];
			tmp->is_directory = true;

			ret->dirs[it[i]] = tmp;
		}
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
	map<string, int> kind;
	int cnt = 0;
	for (int i = 0; i < n + m; i++) {
		string parent;
		FileStat *stat = get();
		cin >> parent >> stat->name >> stat->is_directory;
		info[parent].emplace_back(stat);
		if (!stat->is_directory) kind[stat->name] = 1, ++cnt;
	}
	insert(&root);

	int k;
	cin >> k;
	while (k--) {
		string a, b;
		cin >> a >> b;
		auto src = get_directory(a, 1);
		//assert(src->parent->dirs.count(src->name));
		src->parent->dirs.erase(src->name);
		//assert(!src->parent->dirs.count(src->name));
		move(src, get_directory(b, 1));
	}

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
