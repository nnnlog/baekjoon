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
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	int f = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a % 2 != i % 2) {
			f = 1;
			break;
		}
	}
	cout << (f ? "NO" : "YES") << "\n";
}
