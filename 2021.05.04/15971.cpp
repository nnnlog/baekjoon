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

vector<vpii> graph;
vi dp, mx;

void init(int a, int sum, int curr) {
	for (const auto &[nxt, c] : graph[a]) if (!dp[nxt]) {
		dp[nxt] = sum + c;
		mx[nxt] = max(curr, c);
		init(nxt, sum + c, max(curr, c));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, u, v;
    n = geti();
    u = geti();
    v = geti();
	graph.resize(n + 1);
	dp.resize(n + 1);
	mx.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b, c;
        a = geti();
        b = geti();
        c = geti();
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	dp[u] = -1;
    mx[u] = -1;
	init(u, 0, 0);
	int ans = u == v ? 0 : dp[v] - mx[v];
	cout << ans;
}
