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

#include <sys/stat.h>
#include <sys/mman.h>
signed I[36];char*J=(char*)mmap(0,I[12],1,2,0,fstat(0,(struct stat*)I));
int getu(){int x=0;do x=x*10+*J-'0';while(*++J>='0');++J;return x;}
int geti(){bool e=*J=='-';J+=e;return(e?-1:1)*getu();}

struct A {
	int v, c, d;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	n = geti();
	m = geti();
	vector<vector<A>> graph(n);
	while (m--) {
		int u, v, c, d;
		u = geti(), v = geti(), c = geti(), d = geti();
		graph[u].push_back(A{v, c, d});
		graph[v].push_back(A{u, c, d});
	}
	vector<set<pii>> dist(n);
	queue<pair<pii, pii>> pq;
	dist[0].emplace(0, 0);
	pq.push({{0, 0}, {0, 0}});
	while (!pq.empty()) {
		auto top = pq.front();
		pq.pop();
		int curr = top.first.first, u = top.first.second, c = top.second.first, d = top.second.second;
		if (dist[u].find({c, d}) == dist[u].end()) continue;
		for (const auto &a : graph[u]) {
			int cc = c + a.c, dd = d + a.d;
			if (cc <= 1000 && dd <= 1000) {
				auto it = dist[a.v].upper_bound({cc, dd});
				if (it == dist[a.v].begin()) dist[a.v].emplace(cc, dd), pq.push({{cc * dd, a.v}, {cc, dd}});
				else if (prev(it)->second > dd) {
					if (prev(it)->first == c) dist[a.v].erase(prev(it));
					dist[a.v].emplace(cc, dd);
					pq.push({{cc * dd, a.v}, {cc, dd}});
				}
			}
		}
	}
	int ans = 1e9;
	for (const auto &[a, b] : dist.back()) ans = min(ans, a * b);
	if (ans == 1e9) ans = -1;
	cout << ans;
}
