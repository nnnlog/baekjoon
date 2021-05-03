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

const int N = 1000000;
ll seg[4000000];

ll upd(int node, int start, int end, int k, ll add) {
	if (!(start <= k && k <= end)) return seg[node];
	if (start == end) return seg[node] += add;
	int mid = (start + end) >> 1;
	return seg[node] = upd(node * 2, start, mid, k, add) + upd(node * 2 + 1, mid + 1, end, k, add);
}

int seg_lower_bound(int node, int start, int end, ll value) {
	if (start == end) return start;
	int mid = (start + end) >> 1;
	ll l = seg[node * 2];
	if (l < value) {
		value -= l;
		return seg_lower_bound(node * 2 + 1, mid + 1, end, value);
	}
	return seg_lower_bound(node * 2, start, mid, value);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = geti();
	while (n--) {
		int a = geti();
		if (a == 1) {
			int b = geti();
			int k = seg_lower_bound(1, 1, N, b);
			upd(1, 1, N, k, -1);
			cout << k << "\n";
		} else {
			int b = geti();
			int c = geti();
			upd(1, 1, N, b, c);
		}
	}
}
