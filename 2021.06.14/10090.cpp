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

ll ans = 0;
vi vec;

void merge_sort(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1;
	merge_sort(l, mid), merge_sort(mid + 1, r);
	vi tmp;
	tmp.reserve(r - l + 1);
	int i = l, j = mid + 1;
	while (i <= mid + 1 && j <= r + 1) {
		if (j > r && i > mid) break;
		if (i <= mid && (j > r || vec[i] <= vec[j])) tmp.push_back(vec[i]), ++i;
		else tmp.push_back(vec[j]), ans += mid - i + 1, ++j;
	}
	for (int k = l; k <= r; k++) vec[k] = tmp[k - l];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = getu();
	vec.resize(n);
	for (auto &i : vec) i = getu();
	merge_sort(0, n - 1);
	cout << ans;
}
