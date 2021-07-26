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

int UF[100001], _rank[100001];
stack<pair<int, pii>> backup;
int find(int a) {
	return UF[a] == a ? a : find(UF[a]);
}
int merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		if (_rank[a] < _rank[b]) swap(a, b);
		UF[b] = a;
		int f = _rank[a] == _rank[b];
		if (f) _rank[a]++;
		backup.emplace(f, pii(a, b));
		return 1;
	}
	return 0;
}
void restore() {
	//assert(!backup.empty());
	auto top = backup.top(); backup.pop();
	UF[top.second.second] = top.second.second;
	if (top.first) --_rank[top.second.first];
}

vpii query(1);
vector<vpii> seg;
map<pii, int> lifetime;
vector<pair<pii, pii>> info;

void update(int node, int start, int end, int l, int r, pii edge) {
	if (end < l || start > r) return;
	if (l <= start && end <= r) {
		seg[node].emplace_back(edge);
		return;
	}
	int mid = (start + end) >> 1;
	update(node * 2, start, mid, l, r, edge);
	update(node * 2 + 1, mid + 1, end, l, r, edge);
}

void solve(int node, int start, int end) {
	//cout << start << " " << end << "\n";
	int c = 0;
	for (const auto &[a, b] : seg[node]) c += merge(a, b);//, cout << "merge " << a << " " << b << "\n";
	if (start == end) {
		if (start < query.size()) cout << (find(query[start].first) == find(query[start].second)) << "\n";
	} else {
		int mid = (start + end) >> 1;
		solve(node * 2, start, mid), solve(node * 2 + 1, mid + 1, end);
	}
	while (c--) restore();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (b > c) swap(b, c);
		if (a == 3) query.emplace_back(b, c);
		else if (a == 2) {
			info.emplace_back(pii(lifetime[pii(b, c)], query.size() - 1), pii(b, c));
			lifetime.erase(pii(b, c));
		} else {
			lifetime[pii(b, c)] = query.size();
		}
	}

	for (int i = 1; i <= n; i++) UF[i] = i;
	for (const auto &[key, s] : lifetime) info.emplace_back(pii(s, query.size()), key);//, cout << "push " << key.first << " " << key.second << "\n";

	seg.resize(query.size() * 4);
	for (const auto &[tm, edge] : info) update(1, 1, query.size(), tm.first, tm.second, edge);

	solve(1, 1, query.size());
}
