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

int n;
vector<vi> graph;
ll ans = 0;
int dfs(int u, int prv) {
	int ret = 1;
	for (const auto &v : graph[u]) {
		if (prv == v) continue;
		ll sz = dfs(v, u);
		ll a = n - sz;
		ans += sz * a + sz * (sz - 1) / 2;
		ret += sz;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	n = getu();
	graph.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b;
        a = getu(), b = getu();
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 1);
	cout << ans;
}
