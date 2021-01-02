#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	int f = 0;
	char first = 0;
	while (n--) {
		string a; cin >> a;
		if (!first) first = a[0];
		if (first != a[0] || first != a.back()) f = 1;
	}
	cout << !f;
}
