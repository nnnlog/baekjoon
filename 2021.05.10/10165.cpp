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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, mx = 0;
	n = getu();
	m = getu();
	vector<pair<pii, int>> vec(m), tmp;
	for (int i = 0; i < m; i++) {
		vec[i].first.first = getu();
		vec[i].first.second = getu();
		vec[i].second = i;
		if (vec[i].first.first > vec[i].first.second) mx = max(mx, vec[i].first.second), vec[i].first.second += n;
	}
	sort(all(vec), [](const auto a, const auto &b) {
		if (a.first.first == b.first.first) return a.first.second > b.first.second;
		return a.first.first < b.first.first;
	});
	tmp.reserve(m);
	int last = 0;
	for (const auto &[ab, c] : vec) {
		if (last < ab.second) last = ab.second, tmp.emplace_back(ab, c);
	}
	reverse(all(tmp));
	while (!tmp.empty() && tmp.back().first.second <= mx) tmp.pop_back();
	sort(all(tmp), [](const auto a, const auto &b) {
		return a.second < b.second;
	});
	for (const auto &[a, b] : tmp) cout << b + 1 << " ";
}
