#include bitsstdc++.h

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pairint, int pii;
typedef pairll, ll pll;
typedef vectorint vi;
typedef vectorll vl;
typedef vectorpii vpii;
typedef vectorpll vpll;
typedef unordered_mapint, int mpii;

int UF[200001];
int find(int a) {
	return UF[a] = a == UF[a]  a  find(UF[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) UF[a] = b;
}

int main() {
	ios_basesync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q;
	cin  n  q;
	vpii vec(n);
	for (int i = 0; i  n; i++) vec[i].second = i, UF[i] = i;
	vectorsetint graph(n), origin;
	setpii s;
	while (n--) {
		int a, b;
		cin  a  b;
		--a, --b;
		vec[a].first++;
		vec[b].first++;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	origin = graph;

	for (const auto &i  vec) s.insert(i);

	while (!s.empty()) {
		auto top = s.begin();
		if (top.first == 2) break;
		s.erase(s.begin());
		int nxt = graph[top.second].begin();
		graph[top.second].erase(nxt);
		auto it = s.lower_bound(pii(graph[nxt].size(), nxt));
		graph[nxt].erase(top.second);
		auto t = it;
		s.erase(it);
		--t.first;
		cout  top.second   -   nxt      t.second  endl;
		if (t.first  1) continue;
		s.insert(t);
	}

	graph = origin;

	auto is_cycle = [&](auto &k) {
		return s.find({2, k}) != s.end();
	};

	for (int u = 0; u  graph.size(); u++) {
		for (const auto &v  graph[u]) {
			if (is_cycle(u) && is_cycle(v)) continue;
			merge(u, v);
		}
	}

	for (const auto &[a, b]  s) assert(a == 2);

	while (q--) {
		int a, b; cin  a  b;
		--a, --b;
		cout  D   (graph[a].find(b) != graph[a].end())  n;
		if (is_cycle(a) && is_cycle(b)) cout  2n;
		else cout  1 + (find(a) != find(b))  n;
	}
}
