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

vi UF;

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


	int n;
	cin >> n;
	UF.resize(n + 1);
	iota(all(UF), 0);
	int m = n - 2;
	while (m--) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	int a = find(1);
	for (int i = 2; i <= n; i++)
		if (a != find(i)) {
			cout << "1 " << i;
			break;
		}
}
