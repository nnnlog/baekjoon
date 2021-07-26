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

struct A{
	int x, y, remove, id;
	bool operator< (A& b) const {
		return x == b.x ? remove < b.remove : x < b.x;
	}
};

int UF[100000];
int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) UF[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q; cin >> n >> q;
	for (int i = 0; i <= n; i++) UF[i] = i;
	vector<A> vec;
	vec.reserve(2 * n);
	for (int i = 1; i <= n; i++) {
		int a, b, c; cin >> a >> b >> c;
		vec.push_back({a, c, 0, i});
		vec.push_back({b, c, 1, i});
	}
	sort(all(vec));
	set<pii> Y;
	int adding = 0;
	for (const auto &a : vec) {
		if (a.remove && adding) { //check
			int last = Y.begin()->second;
			for (const auto &[a, b] : Y) merge(last, b), last = b;
			adding = 0;
		}
		if (a.remove) { //remove
			Y.erase({a.y, a.id});
		} else {
			Y.insert({a.y, a.id});
			adding = 1;
		}
	}
	while (q--) {
		int a, b; cin >> a >> b;
		cout << (find(a) == find(b)) << "\n";
	}
}
