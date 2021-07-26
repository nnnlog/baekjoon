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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	multiset<int, greater<>> s;
	for (int i = 0; i < n * n; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	vi vec;
	for (int i = 0; i < n; i++) {
		int top = *s.begin();
		s.erase(s.begin());
		
		for (const auto &j : vec) {
			int g = gcd(j, top);
			s.erase(s.find(g));
			s.erase(s.find(g));
		}
		vec.push_back(top);
	}

	for (const auto &i : vec) cout << i << " ";
}
