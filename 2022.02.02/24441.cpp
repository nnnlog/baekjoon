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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//vi ok(1e6 + 1);
    mpii ok;
	ok[1] = 1;
	
	ordered_set S;
	for (int i = 1; i < 1e6; i += 2) S.insert(i);
	int base = 1;
	while (base < S.size()) {
		int a = *S.find_by_order(base++);
		ok[a] = 1;

		for (int i = S.size() / a; i >= 1; i--) S.erase(S.find_by_order(i * a - 1));
	}

	int T;
	cin >> T;
	while (T--) {
		int a;
		cin >> a;
		cout << (ok.count(a) ? "lucky" : "unlucky") << "\n";
	}
}
